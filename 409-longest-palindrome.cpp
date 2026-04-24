#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <climits>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for (auto& c : s) {
            hash[c]++;
        }

        int output = 0;
        bool containsOdd = false;

        for (auto& [ch, count] : hash) {
            output += count;          // add all
            if (count % 2 == 1) {
                output -= 1;          // trim the odd one out
                containsOdd = true;
            }
        }

        return containsOdd ? output + 1 : output;
    }
};