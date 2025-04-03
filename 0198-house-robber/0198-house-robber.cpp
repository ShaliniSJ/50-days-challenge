class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0,prev = 0,curr = 0;
        for(auto e:nums){
            res = max(res,max(curr,prev+e));
            prev = curr;
            curr = res;
        }
        return res;
    }
};