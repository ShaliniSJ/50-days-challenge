class Solution {
public:
    bool helper(int k, int num,vector<int>& nums){
        int i=0,cnt = 0;
        while(i < nums.size()){
            if(nums[i] <= num)cnt++,i+=2;
            else i++;
            if(cnt == k)break;
        }
        return cnt == k;
    }

    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end()), r = *max_element(nums.begin(),nums.end());
        int res= 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(helper(k,mid,nums)){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};