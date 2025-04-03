class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(),m=w2.size();
        if(w2.empty())return n;
        else if(w1.empty())return m;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)dp[0][i] = i;
        for(int i=1;i<=n;i++)dp[i][0] = i;
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
        }
        return dp[n][m];
    }
};