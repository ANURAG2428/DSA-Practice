class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // If k is even or divisible by 5, no solution exists
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        
        int remainder = 0;
        for (int length = 1; length <= k; length++) {
            remainder = (remainder * 10 + 1) % k;
            
            // If remainder becomes 0, we found our answer
            if (remainder == 0) {
                return length;
            }
        }
        
        return -1;
    }
};