class Solution {
public:

    int res(vector<int>& prices,int i,vector<vector<int>>& dp,int buy){
        if(i>=prices.size()) return 0;
        int pick=0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy==0){
            pick=res(prices,i+1,dp,1)-prices[i];
        }

        else if(buy==1){
            pick=res(prices,i+2,dp,0)+prices[i];
        }
        int np=res(prices,i+1,dp,buy);
        return dp[i][buy]=max(pick,np);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return res(prices,0,dp,0);
    }
};