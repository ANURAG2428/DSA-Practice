class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // Har bit (0 se 31) tak check karenge
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int num : nums) {
                // Agar i-th bit set hai, toh count badhao
                if (num & (1 << i)) {
                    sum++;
                }
            }
            // Agar ye bit 3 se divide nahi hoti,
            // iska matlab ye bit unique number me present hai
            if (sum % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};
