class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<vector<int>,vector<string>>mp;
        for(auto s:strs){
            vector<int> temp(26,0);
            for(auto c:s)temp[c - 'a']++;
            mp[temp].push_back(s);
        }
        for(auto [temp,vec] : mp)res.push_back(vec);
        return res;
    }
};