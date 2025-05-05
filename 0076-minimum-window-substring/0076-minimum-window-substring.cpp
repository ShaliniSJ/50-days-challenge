class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        // unordered_map<char,int>window;
        for(auto a:t)freq[a]++;
        int uniq = freq.size();
        int l = 0, start = 0, n = s.size(), len = INT_MAX, cnt = 0;
        for(int r=0;r<n;r++){
            freq[s[r]]--;
            if(freq[s[r]] == 0)cnt++;
            if(cnt == uniq){
                while(cnt == uniq){
                    freq[s[l]]++;
                    if(freq[s[l]] > 0)cnt--;
                    l++;
                }
                if(len > r-l+2){
                    start = l-1;
                    len = r - start + 1;
                }
            }
        }
        if(len == INT_MAX)return "";
        return s.substr(start, len);
    }
};

// A D O B E C O D E B  A  N  C
// 0 1 2 3 4 5 6 7 8 9 10 11 12
//                      l     r