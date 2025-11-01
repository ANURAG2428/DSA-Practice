class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount; 
        // Ye map rakhega har prefix sum kitni baar aaya hai
        
        int count = 0;   // Kitne subarrays ka sum == k hai
        int sum = 0;     // Current prefix sum

        prefixSumCount[0] = 1; 
        // Important: agar prefix sum khud hi k ho jaye to handle karne ke liye

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // Ab tak ka prefix sum

            // Check karo kya koi aisa prefix sum exist karta hai jisse current sum - old sum = k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Ab current prefix sum ko map me daal do
            prefixSumCount[sum]++;
        }

        return count;
    }
};