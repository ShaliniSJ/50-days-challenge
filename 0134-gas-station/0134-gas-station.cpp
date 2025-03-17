class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff = 0, totg = 0, totc = 0,res = 0;
        for(int i=0;i<gas.size();i++){
            totg += gas[i];
            totc += cost[i];
            diff += gas[i] - cost[i];
            if(diff < 0){
                diff = 0;
                res = i+1;
            }
        }
        if(totg < totc)return -1;
        return res;
    }
};