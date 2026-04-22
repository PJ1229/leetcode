/*
bruh this one easy i was def over complicating it

ex:
[-2,1,-3,4,-1,2,1,-5,4]

use prefixes
[-2 | 1 -3 4 -1 2 1 -5 4]
  ^
[-2 | 1 -3 4 -1 2 1 -5 4]
      ^
ignore -2 since prefix (-2) negative
[-2 | 1 -3 4 -1 2 1 -5 4]
         ^
[-2 | 1 -3 | 4 -1 2 1 -5 4]
             ^
ignore [1, -3] since prefix (-2) negative
[-2 | 1 -3 | 4 -1 2 1 -5 4]
                ^
[-2 | 1 -3 | 4 -1 2 1 -5 4]
                  ^
[-2 | 1 -3 | 4 -1 2 1 -5 4]
                    ^

at every point check if max

dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        return solve(nums, 0, false, dp);
    }
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
        return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
    }
};
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curSum = 0;
        for(auto& n : nums) {
            if(curSum < 0) curSum = 0;
            curSum += n;
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
    }
};