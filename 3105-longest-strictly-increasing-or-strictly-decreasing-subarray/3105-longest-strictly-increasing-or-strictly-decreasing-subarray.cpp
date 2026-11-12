class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=1;
        int n = nums.size();
        int inc=1;
        int dec=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                inc++;
                maxi=max(maxi,inc);
            }
            else inc=1;
            if(nums[i]<nums[i-1]){
                dec++;
                maxi=max(maxi,dec);
            }
            else dec=1;
        }
        return maxi;
    }
};