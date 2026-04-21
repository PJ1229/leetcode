/*
1 step: dp = dp[i-1] + 1 (only one way to get there)
2 step: dp = dp[i-2] + 2 (you could do 1>1 or just 2)
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1; // 1
        dp[1] = 1; // 1
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/*
takes n steps to get to top
can either climb 1 or 2 steps
how many ways to climb to top

ex:
n = 3
1, 1, 1
1, 2
2, 1

using dp
dp[n] = ways to get to ith step
i: [0,n]

dp for n=3
i: 0 1 2
w: 1 2 3


*/