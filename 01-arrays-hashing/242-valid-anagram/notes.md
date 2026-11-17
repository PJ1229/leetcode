# [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)

- **Problem:** [https://leetcode.com/problems/valid-anagram/](https://leetcode.com/problems/valid-anagram/)
- **Topic:** Arrays & Hashing
- **Difficulty:** Easy
- **Date:** 2026-11-17

Notes come from the screen recording of this solve (C++, roughly minute 13 to 30 of the video).

## Pattern

Frequency counting over a fixed alphabet. Lowercase letters only, so a 26-slot array replaces a hash map.

## Key insight

- First thought was two hash maps and compare them. He was not sure how to compare maps, and the intuition that there was a simpler way was right.
- Turn a character into an index with `c - 'a'` and count in an `int[26]`.
- One counter is enough: add 1 for each letter of `s`, subtract 1 for each letter of `t`. If the strings are anagrams every slot ends at 0.
- Compare the lengths first. Different lengths can never be anagrams, so return `false` immediately.

## Complexity

- **Time:** O(n).
- **Space:** O(1), a fixed 26 ints regardless of input size.

## Mistakes

- Sized the count vector wrong at first (not the full alphabet), which gave a "read past the end of a vector" error from LeetCode. Fix: size it to 26.
- Forgot the length check, so `s = "a"`, `t = "ab"` returned the wrong answer. Added `s.size() != t.size()`.
- Spent time debugging the char to index conversion with `static_cast` before it clicked.
- First version used two counters and beat 100% on time but only about 42% on memory. Merging into one counter (add for `s`, subtract for `t`) was the improvement.
