#!/usr/bin/env python3
"""Load and check the NeetCode 150 list in problems.yaml.

The list was checked on 2026-11-16 against neetcode-gh/leetcode
(.problemSiteData.json, neetcode150 entries, roadmap order) and against
LeetCode questionFrontendId, title, difficulty, and isPaidOnly.
"""

from __future__ import annotations

import sys
from collections import Counter
from dataclasses import dataclass
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parent
PROBLEMS_PATH = ROOT / "problems.yaml"

STATUSES = ("todo", "solved", "review")
DIFFICULTIES = ("Easy", "Medium", "Hard")
DONE = ("solved", "review")


class ListError(ValueError):
    """problems.yaml failed a structural check."""


@dataclass(frozen=True)
class Topic:
    id: str
    directory: str
    name: str
    count: int


# Roadmap order from NeetCode. Counts are the neetcode150 problems in each pattern.
TOPICS: tuple[Topic, ...] = (
    Topic("arrays-hashing", "01-arrays-hashing", "Arrays & Hashing", 9),
    Topic("two-pointers", "02-two-pointers", "Two Pointers", 5),
    Topic("sliding-window", "03-sliding-window", "Sliding Window", 6),
    Topic("stack", "04-stack", "Stack", 7),
    Topic("binary-search", "05-binary-search", "Binary Search", 7),
    Topic("linked-list", "06-linked-list", "Linked List", 11),
    Topic("trees", "07-trees", "Trees", 15),
    Topic("tries", "08-tries", "Tries", 3),
    Topic("heap-priority-queue", "09-heap-priority-queue", "Heap / Priority Queue", 7),
    Topic("backtracking", "10-backtracking", "Backtracking", 9),
    Topic("graphs", "11-graphs", "Graphs", 13),
    Topic("advanced-graphs", "12-advanced-graphs", "Advanced Graphs", 6),
    Topic("1d-dp", "13-1d-dp", "1-D DP", 12),
    Topic("2d-dp", "14-2d-dp", "2-D DP", 11),
    Topic("greedy", "15-greedy", "Greedy", 8),
    Topic("intervals", "16-intervals", "Intervals", 6),
    Topic("math-geometry", "17-math-geometry", "Math & Geometry", 8),
    Topic("bit-manipulation", "18-bit-manipulation", "Bit Manipulation", 7),
)

TOPIC_BY_ID = {topic.id: topic for topic in TOPICS}
FIELDS = (
    "number",
    "title",
    "slug",
    "url",
    "topic",
    "difficulty",
    "status",
    "solved_date",
    "premium",
)


def problem_dir(problem: dict) -> Path:
    topic = TOPIC_BY_ID[problem["topic"]]
    return ROOT / topic.directory / f"{problem['number']}-{problem['slug']}"


def solution_file(problem: dict) -> Path:
    return problem_dir(problem) / "solution.cpp"


def notes_file(problem: dict) -> Path:
    return problem_dir(problem) / "notes.md"


def has_solution(problem: dict) -> bool:
    return solution_file(problem).is_file()


def iter_solution_files() -> list[Path]:
    found = []
    for path in ROOT.rglob("solution.cpp"):
        parts = path.relative_to(ROOT).parts
        if any(part.startswith(".") for part in parts):
            continue
        found.append(path)
    return sorted(found)


def stray_solution_files(problems: list[dict]) -> list[Path]:
    expected = {solution_file(problem).resolve() for problem in problems}
    return [path for path in iter_solution_files() if path.resolve() not in expected]


def streak_stats(dates: list[date], today: date) -> tuple[int, int, date | None]:
    """Return the current streak, the longest streak, and the latest date.

    A streak is consecutive calendar days with at least one solved_date.
    The current streak stays alive through the day after the latest solve.
    """
    unique = sorted(set(dates))
    if not unique:
        return 0, 0, None

    longest = 1
    run = 1
    for previous, current in zip(unique, unique[1:]):
        if (current - previous).days == 1:
            run += 1
            longest = max(longest, run)
        else:
            run = 1

    latest = unique[-1]
    present = set(unique)
    current_run = 0
    cursor = latest
    while cursor in present:
        current_run += 1
        cursor = date.fromordinal(cursor.toordinal() - 1)

    if (today - latest).days > 1:
        current_run = 0
    return current_run, longest, latest


def progress_bar(done: int, total: int, width: int = 24) -> str:
    if done <= 0 or total <= 0:
        filled = 0
    elif done >= total:
        filled = width
    else:
        filled = min(width - 1, max(1, round(done * width / total)))
    return "█" * filled + "░" * (width - filled)


def load_problems(path: Path | None = None) -> list[dict]:
    text = (path or PROBLEMS_PATH).read_text(encoding="utf-8")
    problems = _parse(text)
    _validate(problems)
    return problems


def _parse(text: str) -> list[dict]:
    problems: list[dict] = []
    current: dict | None = None
    for lineno, raw in enumerate(text.splitlines(), 1):
        stripped = raw.strip()
        if not stripped or stripped.startswith("#"):
            continue
        if raw.startswith("- "):
            if current is not None:
                problems.append(current)
            current = {}
            body = raw[2:].strip()
        elif raw.startswith("  ") and not raw.startswith("   "):
            if current is None:
                raise ListError(f"line {lineno}: field before a problem")
            body = stripped
        else:
            raise ListError(f"line {lineno}: expected '- key:' or '  key:'")
        if not body:
            raise ListError(f"line {lineno}: missing field")
        key, separator, value = body.partition(":")
        if not separator or not key or key != key.strip():
            raise ListError(f"line {lineno}: expected key: value")
        key = key.strip()
        if current is None:
            raise ListError(f"line {lineno}: field before a problem")
        if key in current:
            raise ListError(f"line {lineno}: duplicate field {key}")
        current[key] = _scalar(value.strip(), lineno)
    if current is not None:
        problems.append(current)
    return problems


def _scalar(raw: str, lineno: int):
    if raw in ("null", "~", ""):
        return None
    if raw == "true":
        return True
    if raw == "false":
        return False
    if len(raw) >= 2 and raw[0] == '"' and raw[-1] == '"':
        return raw[1:-1].replace('\\"', '"').replace("\\\\", "\\")
    if raw.isdigit() or (raw.startswith("-") and raw[1:].isdigit()):
        return int(raw)
    # Bare words, slugs (3sum), dates, and URLs. Titles with spaces stay quoted.
    allowed = set("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789:/._+-")
    if raw and all(ch in allowed for ch in raw):
        return raw
    raise ListError(f"line {lineno}: quote this value: {raw!r}")


def _validate(problems: list[dict]) -> None:
    expected = sum(topic.count for topic in TOPICS)
    if len(problems) != expected:
        raise ListError(f"expected {expected} problems, found {len(problems)}")

    seen_numbers: set[int] = set()
    seen_slugs: set[str] = set()
    topic_counts: Counter[str] = Counter()
    topic_order: list[str] = []

    for index, problem in enumerate(problems, 1):
        missing = [field for field in FIELDS if field not in problem]
        extra = [field for field in problem if field not in FIELDS]
        label = problem.get("number", index)
        if missing or extra:
            raise ListError(f"problem {label}: missing {missing or '-'}, unexpected {extra or '-'}")

        number = problem["number"]
        if isinstance(number, bool) or not isinstance(number, int) or number <= 0:
            raise ListError(f"problem {label}: number must be a positive integer")
        if number in seen_numbers:
            raise ListError(f"duplicate number {number}")
        seen_numbers.add(number)

        slug = problem["slug"]
        if not isinstance(slug, str) or not slug or not all(ch.islower() or ch.isdigit() or ch == "-" for ch in slug):
            raise ListError(f"problem {number}: slug must be a lowercase LeetCode slug")
        if slug in seen_slugs:
            raise ListError(f"duplicate slug {slug}")
        seen_slugs.add(slug)

        title = problem["title"]
        if not isinstance(title, str) or not title.strip():
            raise ListError(f"problem {number}: title is empty")

        url = f"https://leetcode.com/problems/{slug}/"
        if problem["url"] != url:
            raise ListError(f"problem {number}: url must be {url}")

        topic = problem["topic"]
        if topic not in TOPIC_BY_ID:
            raise ListError(f"problem {number}: unknown topic {topic!r}")
        topic_counts[topic] += 1
        if not topic_order or topic_order[-1] != topic:
            if topic in topic_order:
                raise ListError(f"problem {number}: topic {topic} is split in the file")
            topic_order.append(topic)

        if problem["difficulty"] not in DIFFICULTIES:
            raise ListError(f"problem {number}: difficulty must be Easy, Medium, or Hard")
        if problem["status"] not in STATUSES:
            raise ListError(f"problem {number}: status must be todo, solved, or review")
        if not isinstance(problem["premium"], bool):
            raise ListError(f"problem {number}: premium must be true or false")

        solved = _parse_date(problem["solved_date"], number)
        if problem["status"] == "todo" and solved is not None:
            raise ListError(f"problem {number}: todo problems keep solved_date null")
        problem["solved_date"] = solved

    expected_order = [topic.id for topic in TOPICS]
    if topic_order != expected_order:
        raise ListError("topics are not in NeetCode roadmap order")
    for topic in TOPICS:
        if topic_counts[topic.id] != topic.count:
            raise ListError(
                f"{topic.name}: expected {topic.count} problems, found {topic_counts[topic.id]}"
            )


def _parse_date(value, number: int) -> date | None:
    if value is None or isinstance(value, date):
        return value
    if not isinstance(value, str):
        raise ListError(f"problem {number}: solved_date must be YYYY-MM-DD or null")
    try:
        return date.fromisoformat(value)
    except ValueError as exc:
        raise ListError(f"problem {number}: solved_date must be YYYY-MM-DD or null") from exc


def summary(problems: list[dict]) -> str:
    diffs = Counter(problem["difficulty"] for problem in problems)
    premium = sum(problem["premium"] for problem in problems)
    return (
        f"{len(problems)} problems across {len(TOPICS)} topics\n"
        f"{diffs['Easy']} easy, {diffs['Medium']} medium, {diffs['Hard']} hard, {premium} premium"
    )


def main() -> int:
    try:
        problems = load_problems()
    except (OSError, ListError) as exc:
        print(f"problems.yaml: {exc}", file=sys.stderr)
        return 1
    print(summary(problems))
    return 0


if __name__ == "__main__":
    sys.exit(main())
