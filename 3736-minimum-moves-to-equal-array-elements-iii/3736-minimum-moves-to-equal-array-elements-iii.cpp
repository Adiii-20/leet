class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int op=0;
        for(int x:nums){
            op=op+maxi-x;
        }
        return op;
    }
};