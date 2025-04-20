class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 2 * 2 = 4 +1 because buy, sell = 2 states then we have two transation so 4 states 
        // one state for outoff bound error 
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 3; j >= 0; j--) {
                if (j % 2 == 0) { //buy state
                    // either buy here or dont buy (have the previous best transaction)
                    dp[i][j] = max(-prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                } else { // sell state = weather sell in current, or dont sell (copy previous transaction)
                    dp[i][j] = max(prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
