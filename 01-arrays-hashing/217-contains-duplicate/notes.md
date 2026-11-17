# [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

- **Problem:** [https://leetcode.com/problems/contains-duplicate/](https://leetcode.com/problems/contains-duplicate/)
- **Topic:** Arrays & Hashing
- **Difficulty:** Easy
- **Date:** 2026-11-17

Notes come from the screen recording of this solve (C++, about 13 minutes of the video). Complexity is read off the final code; it was not stated aloud.

## Pattern

Hash set membership. Remember what you have already seen and stop at the first repeat.

## Key insight

- First idea was a lookup table indexed by value, but the values are too large for that (he read the value range, which is up to about 10^9 on LeetCode, and said that was way too big), so he switched to a hash map of counts.
- The count map worked but ran slow and used a lot of memory. A hash set is enough because you only need "seen before", not a count.
- `std::set` is an ordered tree, so each insert costs O(log n). `std::unordered_set` is a hash table and stores only keys, so it is faster and uses less memory than a map of pairs.
- `insert()` returns a pair. If `.second` is false the value was already there, so return `true` right away. That combines the check and the insert into one step.
- Solution code also calls `reserve(nums.size())` to avoid rehashing; that detail was not discussed in the recording.

## Complexity

- **Time:** O(n) average (one hash insert per element). The `std::set` attempt was O(n log n).
- **Space:** O(n) for the set.

## Mistakes

- Started with an `unordered_map` of counts. The first run gave a wrong answer, then it passed but was slow with poor memory.
- Next tried building a `std::set` and comparing its size to `nums.size()`. It worked but did not beat the hash version, which led to the set-vs-hash-set lesson above.
- Was rusty on C++ syntax (how to declare a map or set), and forgot to start the timer.
