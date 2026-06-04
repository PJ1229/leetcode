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
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_set<char> window;
        int l = 0, out = 0;

        for (int r = 0; r < s.size(); r++) {
            while (window.count(s[r])) {
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            out = max(out, r - l + 1);
        }

        return out;
    }
};
