class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (is_sorted(nums.begin(), nums.end())) return 0;

        int ind = max_element(nums.begin(), nums.end()) - nums.begin();

        if (is_sorted(nums.begin(), nums.begin() + ind + 1) &&
            is_sorted(nums.begin() + ind + 1, nums.end()) &&
            nums[n - 1] < nums[0])
            return min(ind + 1, n - ind + 1);

        if (is_sorted(nums.begin(), nums.begin() + ind, greater<int>()) &&
            is_sorted(nums.begin() + ind, nums.end(), greater<int>()) &&
            (ind == 0 || nums[n - 1] == nums[0] + 1)) {
            int d = nums[0];
            return min((d + 1) % n + 1, 1 + (n - nums[n - 1]) % n);
        }

        return -1;
    }
};
