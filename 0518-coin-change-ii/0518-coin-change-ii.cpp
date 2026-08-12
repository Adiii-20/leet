class Solution {
public:
    int coin(int amount, vector<int>& coins,int i,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=0;
        if(coins[i]<=amount)
            pick=coin(amount-coins[i],coins,i,dp);
        int np=coin(amount,coins,i-1,dp);
        return dp[i][amount]=pick+np;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return coin(amount,coins,coins.size()-1,dp);
    }
};