class Solution {
public:

    int part( vector<int>& arr , int ind , int k , vector<int>& dp){
        if(ind>=arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int maxii=INT_MIN;
        int maxim=INT_MIN;
        int len=0;
        for(int i=ind;i<min((int)arr.size(),ind+k);i++){
            len++;
            maxim=max(maxim,arr[i]);
            int sum=len*maxim + part(arr, i+1, k, dp);
            maxii=max(maxii,sum);
        }
        return dp[ind] = maxii;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        if(n==1) return arr[0];
        vector<int>dp(n,-1);
        return part(arr,0,k,dp);
    }
};