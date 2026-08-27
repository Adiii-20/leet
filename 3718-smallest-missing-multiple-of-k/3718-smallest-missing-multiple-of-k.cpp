class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int num=k;
        for(int i=0;i<n;i++){
            if(nums[i]==num){
                num=num+k;
            }
            else if(nums[i]>num) break;
        }
        return num;
    }
};