class Solution {
public:
    int trap(vector<int>& h) {
        int res = 0;
        int n = h.size();
        int maxL = h[0],maxR = h[n-1];
        int l = 0,r=n-1;
        while(l < r){
            if(maxL <= maxR){
                l++;
                if(maxL - h[l] > 0)res += maxL-h[l];
                else maxL = h[l];
            }
            else{
                r--;
                if(maxR - h[r] > 0)res += maxR - h[r];
                else maxR = h[r];
            } 
        }
        return res;
    }
};