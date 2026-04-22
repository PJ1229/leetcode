/*
REDO PROBLEM

definitely need a 2d map for dp
i think this is just a restructed knapsack problem

skip item i: dp[i][w] = dp[i-]
take

try to find min

example 1:
i think i flipped it
left 11 10 9 8 7 6 5 4 3 2 1
dp
1    11 10 9 8 7 6 5 4 3 2 1
2    6  5  5 4 4 3 3 2 1 1 1
5    3  

left 1  2  3  4  5  6
dp
1    1* 2  3  4  5  6
2    0  1  3*
5    

want to access the value at dp 1

int rows = 3, cols = 4;
vector<vector<int>> vec2D(rows, vector<int>(cols, 0));
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        // dp: 11 11 11 11 11 11 11 11 11 11 11

        dp[0] = 0;
        // dp: 0 11 11 11 11 11 11 11 11 11 11

        for(int w = 1; w <= amount; w++) { // repeats for amount (11 times)
            for(int i = 0; i < coins.size(); i++) { // repeats for amount of coins [1,2,5]

                // w=2, i=2

                if(coins[i] <= w) { // i == 2
                    dp[w] = min(dp[w], 1+dp[w-coins[i]]); //2 vs 1+dp[2-2] = 1+0 = 1

                    /*
                    so it checks every coin
                    i think i get it
                    still pretty confusing def gotta do this one again
                    */
                    // dp: 0 1 1 11 11 11 11 11 11 11 11
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];

        /*
        dp[weight][amount]
        rows: weight
        cols: amount
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0)); 

        int rows = coins.size();
        int cols = amount;

        for(int i=0; i<coins.size(); i++) {
            for(int w=0; w<amount; w++) {
                int skip = dp[i-1][w];
                int take = 1 + dp[i-1][w-coins[i]];
                dp[i][w] = min(skip, take);
            }
        }
        return dp[rows][cols];
        */
    }
};