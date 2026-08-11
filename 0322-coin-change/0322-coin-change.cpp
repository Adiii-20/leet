class Solution {
public:

    int coin(vector<int>& coins, int amount,vector<vector<int>>& memo,int i){
        if(amount==0 ) return 0;
        if(i<0) return INT_MAX;
        int pick=INT_MAX;
        if(memo[i][amount]!=-1) return memo[i][amount];
        if(coins[i]<=amount){
            int res=coin(coins,amount-coins[i],memo,i);
            if(res!=INT_MAX) pick=res+1;
        }
        int np=coin(coins,amount,memo,i-1);
        return memo[i][amount]=min(pick,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>memo(n,vector<int>(amount+1,-1));
        int ans=coin(coins,amount,memo,n-1);
        return ans!=INT_MAX?ans:-1;
    }
};