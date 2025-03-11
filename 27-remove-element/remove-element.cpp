// tc o(n) sc o(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)return 0;
        int n = nums.size(),res = n;
        for(int i=0;i<n;i++){
            if(nums[i] == val){
                int j = i+1;
                while(j< n && nums[j] ==val)j++;
                if(j < n)swap(nums[i],nums[j]);
                else{
                    res = i;
                    return res;
                }
            }
        }
        return res;
    }
};