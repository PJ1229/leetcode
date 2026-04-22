/*
needed a little help figuring out exact sol. maybe do again

imo best way it to use sliding window
but how can we do this with dp

must buy before sell

prices = [7,1,5,3,6,4]

can be broken into smaller...
prices = [7,1,5,3,6] sol: 5
prices = [7,1,5,3] sol: 4
prices = [7,1,5] sol: 4
prices = [7,1] sol: -6

this makes the dp:
0  1    2    3    4    5 
  [0,1][1,2][1,2][1,4][1,4]
* -6    4    4    5    5
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        int minSoFar = prices[0];
        for(int i=1; i<prices.size(); i++) {
            dp[i] = max(dp[i-1], prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }
        return dp[prices.size() - 1];
    }
};