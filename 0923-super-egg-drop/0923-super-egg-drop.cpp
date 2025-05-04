class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[k][n] represent the minimum number of moves needed to find the critical floor with k eggs and n floors
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        // Base case: 0 floors requires 0 moves, and 1 floor requires 1 move
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        // Base case: With 1 egg, we need j moves for j floors
        for (int j = 0; j <= n; j++) {
            dp[1][j] = j;
        }
        // Fill the DP table
        for (int eggs = 2; eggs <= k; eggs++) {
            for (int floors = 2; floors <= n; floors++) {
                int low = 1, high = floors;
                int result = floors;  // Worst case is dropping from every floor

                // Use binary search to find the optimal floor to drop the egg from
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    int break_case = dp[eggs - 1][mid - 1];  // Egg breaks
                    // so egg-1 and we search in lower floors
                    int no_break_case = dp[eggs][floors - mid];  // Egg doesn't break
                    // so we dont lose egg and search in upper floor
                    
                    // The worst case when dropping from the mid floor
                    int worst_case = max(break_case, no_break_case);

                    if (break_case > no_break_case) {
                        high = mid - 1;  // We should try lower floors
                    } else {
                        low = mid + 1;  // We should try higher floors
                    }

                    result = min(result, 1 + worst_case);  // We add 1 for the current drop
                }

                dp[eggs][floors] = result;
            }
        }
        return dp[k][n];  // Return the result for k eggs and n floors
    }
};