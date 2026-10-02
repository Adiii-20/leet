class Solution {
public:

    void result(vector<string>&ans,int left,int right,string s,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(left<n) result(ans,left+1,right,s+'(',n);
        if(right<left) result(ans,left,right+1,s+')',n);
    }

    vector<string> generateParenthesis(int n) {
        int left=0;
        int right=0;
        vector<string> ans;
        string s="";
        result(ans,left,right,s,n);
        return ans;
    }
};