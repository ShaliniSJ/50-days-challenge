class Solution {
public:
    int strStr(string sen, string pat) {
        string tot = pat + "#" + sen;
        int tl = tot.size(),m = pat.size();
        vector<int>kmp(tl+1);
        kmp[0] = -1;
        int j = -1,i = 0;
        while(i<tl){
            while(j != -1 && tot[i] != tot[j]) j = kmp[j];
            i++;
            j++;
            kmp[i]= j;
            if(kmp[i] == m)return i-m-m-1;
        }
        return -1;
    }
};