/*
can only move down or right

calculate total number of possible unique paths
similar to knight problem

Input: m = 3, n = 7
Output: 28

move 1
0 1 0 ...
1 0 0
0 0 0

move 2
0 0 1 ...
0 2
1 

*/

class Solution {
public:
    bool inBounds(int j, int k, int m, int n) {
        return j < m && j >= 0 && k < n && k >= 0;
    }

    int uniquePaths(int m, int n) {
        if(m <= 1 || n <= 1) return 1;

        int moves = m + n - 2;
        vector<vector<vector<int>>> dp(moves + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        if(m > 1) dp[0][1][0] = 1;
        if(n > 1) dp[0][0][1] = 1;

        for(int i=1; i<moves; i++) {
            for(int j=0; j<m; j++) {
                for(int k=0; k<n; k++) {
                    if(inBounds(j, k+1, m, n)) dp[i][j][k+1] += dp[i-1][j][k];
                    if(inBounds(j+1, k, m, n)) dp[i][j+1][k] += dp[i-1][j][k];
                }
            }
        }

        return dp[moves - 1][m-1][n-1];

    }
};