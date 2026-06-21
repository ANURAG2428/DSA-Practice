class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int sum = 0;
        int n = nums.size();
        int cnt = 0;

        map<int, int> h;

        for(int i = 0; i < n; i++) {

            sum += nums[i];

            // agar starting se current tak ka sum = k
            if(sum == k) {
                cnt++;
            }

            // previous prefix sum check
            if(h.count(sum - k)) {
                cnt += h[sum - k];
            }

            h[sum]++;
        }

        return cnt;
    }
};