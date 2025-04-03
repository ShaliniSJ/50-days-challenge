class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<int>prev(amt+1,INT_MAX-1),curr(amt+1,0);
        // for(auto &e: dp[0]){
        //     e = INT_MAX-1;
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amt;j++){
                int diff = j - coins[i-1];
                if(diff >= 0){
                    curr[j] = min(prev[j],1+curr[diff]);
                }
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        return curr[amt] == INT_MAX-1 ? -1 :curr[amt];
    }
};