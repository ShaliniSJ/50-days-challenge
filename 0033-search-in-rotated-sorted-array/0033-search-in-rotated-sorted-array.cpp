class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int res = 0;
        int low = 0,n = nums.size(),high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target)return mid;
            if(nums[mid] >= nums[low]){
                if(nums[low] <= target && nums[mid] > target)high = mid-1;
                else low = mid+1;
            }
            else{
                if(target <= nums[high] && nums[mid] < target)low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int low = 0;
//         int high = nums.size()-1;
//         while(low <= high){
//             int mid = (low+high)/2;
//             if(nums[mid] == target)return mid;
//             else if(nums[low] <= nums[mid]){// left side is sorted
//                 if(nums[low] <= target && nums[mid] >= target)high = mid-1;
//                 else low = mid+1;
//             }
//             else{
//                 if(nums[mid] <= target && nums[high] >= target)low = mid+1;
//                 else high = mid-1;
//             }
//         }
//         return -1;
//     }
// };