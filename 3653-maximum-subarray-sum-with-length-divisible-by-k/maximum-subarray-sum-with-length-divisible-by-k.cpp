class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // For each modulo class, maintain minimum prefix sum
        vector<long long> minPrefix(k, LLONG_MAX);
        long long ans = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int mod = i % k;

            // If we have seen this modulo before
            if (minPrefix[mod] != LLONG_MAX) {
                ans = max(ans, prefix[i] - minPrefix[mod]);
            }

            // Update minimum prefix sum for this modulo
            minPrefix[mod] = min(minPrefix[mod], prefix[i]);
        }

        return ans;
    }
};
