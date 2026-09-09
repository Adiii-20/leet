class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0) return nums[0];
        int n=nums.size();
        if(n==1 && k%2==1) return -1;
        if(k==n) return *max_element(nums.begin(),nums.end()-1);
        int maxi=-1;
        if(k<n){
            for(int i=0;i<k-1;i++){
                maxi=max(maxi,nums[i]);
            }
            if(nums[k]>maxi) return nums[k];
        }
        else{
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        }
        return maxi;
    }
};