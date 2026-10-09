class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int count=0;
        int i=0;

        while(i<s.size()){

            if(s[i]=='(') {
                st.push('(');
                i++;
            }

            else {

                if(i!=s.size()-1 && s[i+1]==')'){
                    if(!st.empty()){
                        st.pop();
                    }
                    else count++;
                    i=i+2;
                }

                else{
                    count++;
                    if(!st.empty()){
                        st.pop();
                    }
                    else count++;
                    i++;
                }

            }

            }
            int open=0;
            while(!st.empty()) {
                open++;
                st.pop();
            }
        return count+2*open;
    }
};