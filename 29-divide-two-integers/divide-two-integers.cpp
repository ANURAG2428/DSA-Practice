class Solution {
public:
    int divide(int dividend, int divisor) {
        // Agar divisor 0 ho toh division impossible hai, lekin yeh problem mein allowed nahi hai
        if (divisor == 0) return INT_MAX;

        // Sign ka track rakho, kyunki negative or positive result ho sakta hai
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert dividend aur divisor ko positive values mein, taaki hum easier calculation kar sakein
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long quotient = 0;

        // Hum ek efficient way se division karenge using subtraction method
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor, multiple = 1;
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;   // Shift left means multiply by 2
                multiple <<= 1;      // Increase multiple by powers of 2
            }
            absDividend -= tempDivisor;   // Subtract the divisor
            quotient += multiple;         // Add the multiple to the result
        }

        // Agar sign negative hai, toh quotient ko negative kar do
        if (isNegative) {
            quotient = -quotient;
        }

        // Int overflow ka check karna zaroori hai
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return quotient;
    }
};