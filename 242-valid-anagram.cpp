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
    bool isAnagram(string s, string t) {
        map<char, int> cs;
        map<char, int> ct;

        for(auto i : s) {
            cs[i]++;
        }

        for(auto i : t) {
            ct[i]++;
        }

        return cs == ct;
    }
};