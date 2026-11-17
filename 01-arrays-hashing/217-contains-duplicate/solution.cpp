// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/
// Arrays & Hashing · Easy
//
// CI runs: g++ -std=c++20 -Wall solution.cpp && ./a.out

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        seen.reserve(nums.size());          // avoid rehashing
        for (int x : nums) {
            if (!seen.insert(x).second)     // insert fails → already seen
                return true;
        }
        return false;
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

    vector<int> a = {1, 2, 3, 1};
    vector<int> b = {1, 2, 3, 4};
    vector<int> c = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    vector<int> d = {7};

    check(sol.containsDuplicate(a) == true, "example 1");
    check(sol.containsDuplicate(b) == false, "example 2");
    check(sol.containsDuplicate(c) == true, "example 3");
    check(sol.containsDuplicate(d) == false, "single element");

    cout << "All tests passed\n";
    return 0;
}
