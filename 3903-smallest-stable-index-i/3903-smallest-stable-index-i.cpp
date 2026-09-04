class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int mini=*min_element(nums.begin()+i,nums.end());
            if(maxi-mini<=k) return i;
        }
        return -1;
    }
};