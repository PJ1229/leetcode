#!/usr/bin/env python3
"""Create solution.cpp and notes.md for one NeetCode 150 problem.

    python3 new.py 217
    python3 new.py contains-duplicate

Existing files are left untouched.
"""

from __future__ import annotations

import sys

import nc150

USAGE = "usage: python3 new.py <number or slug>"


def main(argv: list[str]) -> int:
    if len(argv) != 2 or argv[1] in ("-h", "--help"):
        print(USAGE, file=sys.stderr)
        return 2
    try:
        problems = nc150.load_problems()
    except (OSError, nc150.ListError) as exc:
        print(f"problems.yaml: {exc}", file=sys.stderr)
        return 1
    try:
        problem = find_problem(problems, argv[1])
    except LookupError as exc:
        print(exc, file=sys.stderr)
        return 2

    folder = nc150.problem_dir(problem)
    folder.mkdir(parents=True, exist_ok=True)
    files = {
        nc150.solution_file(problem): solution_cpp(problem),
        nc150.notes_file(problem): notes_md(problem),
    }
    wrote = False
    for path, content in files.items():
        rel = path.relative_to(nc150.ROOT).as_posix()
        if path.exists():
            print(f"keep  {rel}")
            continue
        path.write_text(content, encoding="utf-8", newline="\n")
        print(f"write {rel}")
        wrote = True
    if not wrote:
        print("already set up")
        return 0
    solution = nc150.solution_file(problem).relative_to(nc150.ROOT).as_posix()
    print(f"\ng++ -std=c++20 -Wall -o /tmp/sol {solution} && /tmp/sol")
    return 0


def find_problem(problems: list[dict], key: str) -> dict:
    text = key.strip()
    marker = "leetcode.com/problems/"
    if marker in text:
        text = text.split(marker, 1)[1]
    text = text.split("?", 1)[0].strip().strip("/")
    if not text:
        raise LookupError("Give a LeetCode number or slug, for example 217 or contains-duplicate.")

    by_number = {problem["number"]: problem for problem in problems}
    by_slug = {problem["slug"]: problem for problem in problems}
    by_folder = {f"{problem['number']}-{problem['slug']}": problem for problem in problems}

    if text in by_folder:
        return by_folder[text]
    if text.isdigit():
        number = int(text)
        if number not in by_number:
            raise LookupError(f"No NeetCode 150 problem numbered {number}.")
        return by_number[number]
    slug = text.lower()
    if slug in by_slug:
        return by_slug[slug]
    raise LookupError(
        f"No NeetCode 150 problem matching {key!r}. Use a number (217) or a slug (contains-duplicate)."
    )


def solution_cpp(problem: dict) -> str:
    topic = nc150.TOPIC_BY_ID[problem["topic"]].name
    number = problem["number"]
    title = problem["title"].replace("*/", "* /")
    url = problem["url"]
    return f"""// {number}. {title}
// {url}
// {topic} · {problem["difficulty"]}
//
// Replace Solution::placeholder() with the LeetCode method. Design problems
// (LRUCache, Trie, MedianFinder, and the others) use their own class name.
// Point the checks in main() at the real method. The checks below pass the
// stub, so this folder can compile while you are still solving it.
// CI runs: g++ -std=c++20 -Wall solution.cpp && ./a.out

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {{
public:
    int placeholder() {{ return 0; }}
}};

static void check(bool cond, const string& name) {{
    if (!cond) {{
        cerr << "FAIL " << name << "\\n";
        exit(1);
    }}
    cout << "ok   " << name << "\\n";
}}

int main() {{
    Solution sol;

    // Replace these with the LeetCode examples once placeholder() is gone.
    // check(sol.twoSum(nums, 9) == vector<int>{{0, 1}}, "example 1");
    check(sol.placeholder() == 0, "example 1");
    check(sol.placeholder() == 0, "example 2");

    cout << "All tests passed\\n";
    return 0;
}}
"""


def notes_md(problem: dict) -> str:
    topic = nc150.TOPIC_BY_ID[problem["topic"]].name
    return f"""# [{problem["number"]}. {problem["title"]}]({problem["url"]})

- **Problem:** [{problem["url"]}]({problem["url"]})
- **Topic:** {topic}
- **Difficulty:** {problem["difficulty"]}
- **Date:**

## Pattern

## Key insight

## Complexity

- **Time:**
- **Space:**

## Mistakes
"""


if __name__ == "__main__":
    sys.exit(main(sys.argv))
