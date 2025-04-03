class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto e:nums){
            if(pq.size() < k)pq.push(e);
            else if( pq.top() < e){
                pq.pop();
                pq.push(e);
            }
        }
        return pq.top();
    }
};