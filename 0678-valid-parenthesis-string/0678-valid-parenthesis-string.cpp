class Solution {
public:
    bool checkValidString(string s) {
        stack<int>left;
        stack<int>mark;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') left.push(i);
            else if(s[i]=='*') mark.push(i);
            else{
                if(!left.empty())left.pop();
                else if(!mark.empty())mark.pop();
                else return false;           
            }
            }
            while(!left.empty() && !mark.empty() && left.top()<mark.top()){
                left.pop();
                mark.pop();
            }
            if(!left.empty()) return false;
            return true;
    }
};