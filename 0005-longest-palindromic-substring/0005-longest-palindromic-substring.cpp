class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n = s.size();
        for(int i=0;i<n;i++){
            string temp = "";
            int l=i,r=i;
            while(l >= 0 && r < n && s[l] == s[r]){
                temp = s.substr(l,r-l+1);
                l--,r++;
            }
            if(temp.size() > res.size())res = temp;
            l = i,r=i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                temp = s.substr(l,r-l+1);
                l--,r++;
            }
            if(temp.size() > res.size())res = temp;
        }
        return res;
    }
};