class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(st.empty() || st.top()!='(') return false;
                else st.pop();
            }
            else if(s[i]=='}'){
                if(st.empty() || st.top()!='{') return false;
                else st.pop();
            }
            else if(s[i]==']'){
                if(st.empty() || st.top()!='[') return false;
                else st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};