// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/
// Arrays & Hashing · Easy
//
// CI runs: g++ -std=c++20 -Wall solution.cpp && ./a.out

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        int count[26] = {};
        for (size_t i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int c : count)
            if (c != 0) return false;
        return true;
    }
};

static void check(bool cond, const string& name) {
    if (!cond) {
        cerr << "FAIL " << name << "\n";
        exit(1);
    }
    cout << "ok   " << name << "\n";
}

int main() {
    Solution sol;

    check(sol.isAnagram("anagram", "nagaram") == true, "example 1");
    check(sol.isAnagram("rat", "car") == false, "example 2");
    check(sol.isAnagram("a", "ab") == false, "different lengths");
    check(sol.isAnagram("aacc", "ccac") == false, "same length, different counts");

    cout << "All tests passed\n";
    return 0;
}
