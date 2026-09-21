class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
         vector<long long> dp(k, 0);
        vector<long long> result(k, 0);

        for (int x : nums) {
            vector<long long> ndp(k, 0);
            ndp[x % k]++;
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newR = (r * (x % k)) % k;
                    ndp[newR] += dp[r];
                }
            }

            dp = ndp;
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};