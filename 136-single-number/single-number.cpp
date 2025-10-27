class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int result = 0;  // Start with 0
        
        // XOR all elements in the array
        for (int num : nums) {
            result ^= num;  // Perform XOR operation
        }

        return result;  // The remaining number is the single one
    }
};