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
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

[1,10,5,5,10,1]

two options:
take dp[i] = nums[i] + dp[i-2]
skip dp[i] = dp[i-1]

find max of both


*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[nums.size()-1];
    }
};