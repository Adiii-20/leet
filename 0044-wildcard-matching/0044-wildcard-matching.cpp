class Solution {
public:
    bool match(string& s, string& p,int i,int j,vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0){
            for(int k=j;k>=0;k--){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(s[i]==p[j] || p[j]=='?') ans=match(s,p,i-1,j-1,dp);
        else if(p[j]=='*') ans=match(s,p,i-1,j,dp)||match(s,p,i,j-1,dp);
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return match(s,p,n-1,m-1,dp);
    }
};