class Solution {
public:

    bool summ(int i,int t,vector<int>& nums,vector<vector<int>>& dp){
        if(t==0) return true;
        if(i>=nums.size()) return false;
        if(dp[i][t]!=-1) return dp[i][t];
        bool take=false;
        if(nums[i]<=t){
            take=summ(i+1,t-nums[i],nums,dp);
        }
        bool nt=summ(i+1,t,nums,dp);
        return dp[i][t]= take || nt;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(sum%2!=0) return false;
        int t=sum/2;
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return summ(0,t,nums,dp);
    }
};