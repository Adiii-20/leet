class Solution {
public:
    vector<string> ans;
    void para(string s,int n,int l,int r){
        if(l>n || r>l) return;
        if(l+r==2*n){
            ans.push_back(s);
            return;
        }
        para(s+'(',n,l+1,r);
        para(s+')',n,l,r+1);
    }
    vector<string> generateParenthesis(int n) {
        para("",n,0,0);
        return ans;
    }
};