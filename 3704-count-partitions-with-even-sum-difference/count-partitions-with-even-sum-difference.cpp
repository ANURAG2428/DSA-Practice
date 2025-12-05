class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; // Dono parts non-empty hone chahiye
        
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int count = 0;
        int leftSum = 0;
        
        // i = 0 to n-2 tak jaayenge
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;
            int diff = leftSum - rightSum;
            
            if (diff % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }
};