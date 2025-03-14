class Solution {
public:
    bool helper(vector<int>& can, long long k, int num){
        long long temp = 0;
        for(auto n:can){
            temp += (n/num);
        }
        if (temp >= k)return 1;
        return 0;
    }
    int maximumCandies(vector<int>& can, long long k) {
        long long low = 1, high = accumulate(can.begin(),can.end(),0LL)/k;
        int res = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(helper(can, k ,mid)){
                res = mid;
                low = mid+1;
            }    
            else {
                high = mid-1;
            }
        }
        return res;
    }
};