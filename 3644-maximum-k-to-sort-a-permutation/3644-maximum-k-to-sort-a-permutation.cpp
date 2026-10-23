class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int num=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                num=num&nums[i];
            }
        }
        if(num==INT_MAX) return 0;
        return num;
    }
};