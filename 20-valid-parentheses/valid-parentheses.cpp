class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s){
            if(st.empty()){
                if(x == ')' || x == '}' || x == ']')return false;
                st.push(x);
            }
            else if((x == ')' && st.top() != '(') || (x == ']' && st.top() != '[') || (x == '}' && st.top() != '{'))return false;
            else if((x == '(') || x == '[' || x== '{')st.push(x);
            else st.pop();
        }
        return st.empty();
    }
};