class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2,nums1);
        int half = (n +m +1)/2;
        int low = 0, high = min(n,half);
        while(low <= high){
            int mid1 = (low+high)/2;
            int mid2 = half-mid1;
            int l1 = mid1 - 1 >= 0 ? nums1[mid1-1] : INT_MIN;
            int l2 = mid2 - 1 >= 0 ? nums2[mid2-1] : INT_MIN;
            int r1 = (mid1 == n) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == m) ? INT_MAX : nums2[mid2];
            if(l1 > r2){
                // move high towards mid
                high = mid1-1;
            }
            else if(l2 > r1)low = mid1+1;
            else {
                if((n+m)&1)return (double)max(l1,l2);
                return (max(l1,l2) +min(r1,r2))/2.0;
            }
        }
        return -1.0;
    }
};