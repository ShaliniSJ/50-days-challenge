class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int res = 0;
        for(auto x:prices){
            mini = min(x,mini);
            res = max(res,x-mini);
        }
        return res;
    }
};