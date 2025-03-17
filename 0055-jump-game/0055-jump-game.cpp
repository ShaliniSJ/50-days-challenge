class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        if(nums.size() == 1)return 1;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi, i+nums[i]);
            if(maxi-1 < i)return false;
            if(maxi >= nums.size()-1)return true;
        }
        return true;
    }
};