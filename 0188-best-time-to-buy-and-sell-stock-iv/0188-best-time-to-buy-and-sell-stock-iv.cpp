class Solution {
public:

    int profit(vector<int>& prices,int c,vector<vector<vector<int>>>& dp,int i, int buy,int k){
        if(i>=prices.size() || c==k) return 0;
        if(dp[i][buy][c]!=-1) return dp[i][buy][c];
        int pick=0;
        if(buy==1){
            pick=profit(prices,c,dp,i+1,0,k)-prices[i];
        }
        else if(buy==0) pick=profit(prices,c+1,dp,i+1,1,k)+prices[i];
        int np=profit(prices,c,dp,i+1,buy,k);
        return dp[i][buy][c]=max(pick,np);
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
        return profit(prices,0,dp,0,1,k);
    }
};