class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorAll = 0;

        // XOR all numbers → result = a ^ b (the two unique numbers)
        for (int n : nums) xorAll ^= n;

        // Find rightmost set bit (where a and b differ)
        long diff = xorAll & -xorAll;

        int a = 0, b = 0;

        // Partition numbers into two groups based on the differing bit
        for (int n : nums) {
            if (n & diff) a ^= n;
            else b ^= n;
        }

        return {a, b};
    }
};
