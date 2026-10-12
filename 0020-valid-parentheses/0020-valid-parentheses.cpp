class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() && (s[i]==')' || s[i]=='}' || s[i]=='}') ){
                return false;
            }
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()=='(' || st.top()=='{' || st.top()=='['){
                if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[') ){
                    st.pop();
                    continue;
                }
                st.push(s[i]);
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};