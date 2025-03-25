class Solution {
public:
    bool dfs(int curr,unordered_map<int,vector<int>>& adj, vector<bool>& vis, vector<bool>& path){
        path[curr] = true;
        vis[curr] = true;
        for(auto nei:adj[curr]){
            if(!vis[nei]){
                if(dfs(nei,adj,vis,path))return true;
            }
            // if its visited using same path
            else if(path[nei])return true;
        }
        // st.push(curr);
        path[curr] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>adj;
        for(auto p:pre){
            adj[p[1]].push_back(p[0]);
        }
        vector<bool>vis(n,0);
        vector<bool>path(n,false);
        bool isCycle = false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                isCycle = dfs(i,adj,vis,path);
                if(isCycle)return {};
            }
        }
        // vector<int>res;
        // while(!st.empty()){
        //     res.push_back(st.top());
        //     st.pop();
        // }
        return true;
    }
    
};