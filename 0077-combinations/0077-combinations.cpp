class Solution {
public:
    void bt(int start,int n,int k, vector<int>temp, vector<vector<int>>& res){
        if(k == 0){
            res.push_back(temp);
            return;
        }
        if(start > n)return;
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            bt(i+1,n,k-1,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        bt(1,n,k,{},res);
        return res;
    }
};