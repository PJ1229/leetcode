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

/*
neetcode solution:
- want all characters to match most common variable
- use hashmap / array to count occurences

ex:
ababba k=2
hashmap
char : freq
a : 1
b : 3

windowlen - count[b] check if > k


check notion for sliding window standard format
*/

class Solution {
public:
    int characterReplacement(string s, int k) { // case: s="AABABBA" k=1
        int left = 0;
        unordered_map<char, int> count;
        int ans = 0; int maxCount = 0;

        for(int right = 0; right < s.size(); right++) { // right = 2
            count[s[right]]++;
            /*
            a : 2
            b : 1
            */

            // winlen=2, maxcount=2
            maxCount = max(maxCount, count[s[right]]);
            while((right - left + 1) - maxCount > k) { // -2 > 1
                count[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
