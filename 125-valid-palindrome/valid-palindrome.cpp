class Solution {
public:
    bool isPalindrome(string s) {
       int i=0;
       string strs = "";
       for(int j=0;j<s.size();j++){
           if(iswalnum(s[j])) strs += tolower(s[j]);
       }
       return helper(strs,i); 
    }
    bool helper(string &s,int i){
        if(i >= s.size()/2) return true;
        if(s[i] != s[s.size()-1-i]) return false;
        return helper(s,i+1);
    }
    
};