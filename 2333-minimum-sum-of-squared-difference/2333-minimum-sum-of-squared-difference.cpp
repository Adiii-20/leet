class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    long long k = (long long)k1 + k2;
    int n = nums1.size();

    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = abs(nums1[i] - nums2[i]);
    }
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += diff[i];
    }
    if (total <= k) return 0;

    int low = 0, high = 100000;

    while (low < high) {
        int mid = low + (high - low) / 2;
        long long need = 0;
        for (int i = 0; i < n; i++) {
            if (diff[i] > mid) {
                need += diff[i] - mid;
            }
        }
        if (need <= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    int limit = low;
    long long used = 0;

    for (int i = 0; i < n; i++) {
        if (diff[i] > limit) {
            used += diff[i] - limit;
            diff[i] = limit;
        }
    }
    k -= used;
    for (int i = 0; i < n && k > 0; i++) {
        if (diff[i] > 0 && diff[i] == limit) {
            diff[i]--;
            k--;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * diff[i] * diff[i];
    }
    return ans;
}
};
