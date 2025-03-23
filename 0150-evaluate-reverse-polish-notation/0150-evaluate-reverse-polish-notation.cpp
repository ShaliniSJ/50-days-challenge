class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>sk;
        unordered_set<string>st = {"+","/","*","-"};
        for(auto e:tokens){
            if(st.find(e) != st.end()){
                string a = sk.top();
                sk.pop();
                string b = sk.top();
                sk.pop();
                int num = 0;
                if(e == "*")num = stoi(b) * stoi(a);
                if(e == "+")num = stoi(b) + stoi(a);
                if(e == "/")num = stoi(b) / stoi(a);
                if(e == "-")num = stoi(b) - stoi(a);
                sk.push(to_string(num));
            }
            else sk.push(e);
        }
        return stoi(sk.top());
    }
};