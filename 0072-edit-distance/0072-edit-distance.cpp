class Solution {
public:

    int count(string& word1, string& word2,int i,int j,vector<vector<int>>& dp){
        if(i<0) return 1+j;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=count(word1,word2,i-1,j-1,dp);
        else{
            int remove=count(word1,word2,i-1,j,dp);
            int replace=count(word1,word2,i-1,j-1,dp);
            int insert=count(word1,word2,i,j-1,dp);
            return dp[i][j]=1+min({remove,replace,insert});
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
        return count(word1,word2,n-1,m-1,dp);
    }
};