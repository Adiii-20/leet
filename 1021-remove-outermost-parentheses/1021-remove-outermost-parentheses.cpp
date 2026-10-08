class Solution {
public:
    string removeOuterParentheses(string s) {
        int left=0;
        int start=0;
        string result;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else left--;
            if(left==0){
                result=result+s.substr(start+1,i-1-start);
                start=i+1;
            }
        }
        return result;
    }
};