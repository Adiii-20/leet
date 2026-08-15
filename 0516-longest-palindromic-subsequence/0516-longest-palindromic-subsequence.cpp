class Solution {
public:

    int count(string& s,string& s2,int i,vector<vector<int>>& dp,int j){
        if(i>=s.size() || j>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s2[j]) return dp[i][j]=1+count(s,s2,i+1,dp,j+1);
        int np=count(s,s2,i+1,dp,j);
        int pick=count(s,s2,i,dp,j+1);
        return dp[i][j]=max(np,pick);
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return count(s,s2,0,dp,0);
    }
};