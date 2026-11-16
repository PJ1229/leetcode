# NeetCode 150

C++ practice for big-tech internship interviews, arranged as the [NeetCode 150](https://neetcode.io/practice) roadmap. Each problem is solved from scratch in this repo: one folder, one `solution.cpp`, one `notes.md`.

## How to use

Start a problem by LeetCode number or slug. `new.py` creates the folder, a compiling `solution.cpp` stub, and a `notes.md` template. Files that are already there stay as they are.

```bash
python3 new.py 217
python3 new.py contains-duplicate
```

Write the LeetCode method on `class Solution` and check the examples from `main()`. Compile it the way CI does:

```bash
g++ -std=c++20 -Wall -o /tmp/sol 01-arrays-hashing/217-contains-duplicate/solution.cpp && /tmp/sol
```

Record the result on that problem in [`problems.yaml`](problems.yaml):

| Field | What to put |
| --- | --- |
| `status` | `todo`, `solved`, or `review` |
| `solved_date` | `YYYY-MM-DD`, or `null` while it is still `todo` |

`solved` is a finished problem. `review` is a finished problem worth another pass. Both count as done. The streak reads `solved_date`.

Regenerate the progress sections of this README:

```bash
python3 readme.py
```

`python3 readme.py --check` exits non-zero when this file is stale. On push, GitHub Actions compiles every `solution.cpp` with `g++ -std=c++20 -Wall`, runs `main()`, and commits a fresh README and progress page when the numbers change.

This introduction lives in [`intro.md`](intro.md). `python3 nc150.py` checks that the list is still the 150, with no duplicate numbers or slugs.

## Progress page

[`docs/index.html`](docs/index.html) is the public dashboard: solved out of 150, progress by topic, easy/medium/hard counts, the current streak, recent solves, and a GitHub link for each solution folder. It is generated from the same `problems.yaml`.

```bash
python3 dashboard.py
```

After a one-time choice of GitHub Actions as the Pages source, the page is published at [pj1229.github.io/leetcode](https://pj1229.github.io/leetcode/).

## C++ conventions

- C++20 and the standard library. Include the headers you use.
- Folder layout is `<topic>/<number>-<slug>/`, for example `01-arrays-hashing/217-contains-duplicate/`.
- `class Solution` uses the LeetCode signature so the method pastes back into the editor. A few design problems use another class name (`LRUCache`, `Trie`, `MedianFinder`). Use that class and keep `main()`.
- `main()` is the local test runner. It returns 0 when every check passes and non-zero when a check fails.
- `using namespace std;` belongs in these solution files.
- `notes.md` holds the pattern, the key insight, time and space complexity, mistakes, and the date.
- Premium LeetCode problems are marked in the roadmap. NeetCode publishes those statements for free.
