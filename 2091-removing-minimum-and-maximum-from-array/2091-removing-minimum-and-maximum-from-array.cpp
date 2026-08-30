class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int first=INT_MIN;
        int second=INT_MAX;
        int ind1=0;
        int ind2=0;
        for(int i=0;i<n;i++){
            if(nums[i]>first){
                first=nums[i];
                ind1=i;
            }
            if(nums[i]<second){
                second=nums[i];
                ind2=i;
            }
        }
        int ans1=max(ind1+1,ind2+1);
        int ans2=max(n-ind1,n-ind2);
        int ans3=min(ind1+1,n-ind1)+min(ind2+1,n-ind2);
        return min({ans1,ans2,ans3});
    }
};