class Solution {
public:
    int maxProfit(int k, vector<int>& nums) {
        int n = nums.size();

        // dp[i][j] represents the max profit from day i with j operations already performed
        // Each transaction has two operations: buy and sell. So max j = 2*k
        vector<vector<int>> dp(n + 1, vector<int>((k * 2) + 1, 0));

        // Start filling the dp table from the end (bottom-up DP)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = (k * 2) - 1; j >= 0; j--) {

                // Even j => Buy operation
                if (j % 2 == 0) {
                    // We have two choices:
                    // 1. Buy at current price (subtract price and move to next state)
                    // 2. Skip buying and move to next day with same operation count
                    dp[i][j] = max(-nums[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                }
                // Odd j => Sell operation
                else {
                    // We have two choices:
                    // 1. Sell at current price (add price and move to next state)
                    // 2. Skip selling and move to next day with same operation count
                    dp[i][j] = max(nums[i] + dp[i + 1][j + 1], dp[i + 1][j]);
                }
            }
        }

        // Return max profit starting from day 0 with 0 operations performed
        return dp[0][0];
    }
};
