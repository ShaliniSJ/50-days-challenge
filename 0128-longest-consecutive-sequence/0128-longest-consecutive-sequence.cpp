class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        unordered_set<int> st;
        for(auto x:nums) st.insert(x);
        int res = 1;
        for(auto x:st){
            if(st.find(x-1) == st.end()){
                int len = 1;
                int n = x;
                while(st.find(n+1) != st.end()){
                    len++;
                    n++;
                }
                res = max(res,len);
            }
        }
        return res;
    }
};