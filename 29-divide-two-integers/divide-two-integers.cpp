class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;
        while (n >= d) {
            int cnt = 0;
            // Check d << (cnt+1) doesn't overflow and is <= n
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += (1LL << cnt);
            n -= (d << cnt);
        }

        if (!sign)
            quotient = -quotient;

        if (quotient > INT_MAX)
            return INT_MAX;
        if (quotient < INT_MIN)
            return INT_MIN;
        return quotient;
    }
};