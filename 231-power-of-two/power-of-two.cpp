class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check if the number is positive and (n & (n - 1)) == 0
        return n > 0 && (n & (n - 1)) == 0;
    }
};
