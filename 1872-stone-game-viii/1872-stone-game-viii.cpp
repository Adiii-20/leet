class Solution {
public:

    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>presum(n,0);
        presum[0]=stones[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+stones[i];
        }
        vector<int>dp(n,0);
        dp[n-1]=presum[n-1];
        for(int i=n-2;i>0;i--){
            dp[i]=max(dp[i+1],presum[i]-dp[i+1]);
        }
        return dp[1];
    }
};