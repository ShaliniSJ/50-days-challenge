class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for (auto &&i:nums){
            if (i < 0)
            pos++;
            else if (i>0)
            neg++;
        }
        if (pos > neg)
        return pos;
        else
        return neg;}
};