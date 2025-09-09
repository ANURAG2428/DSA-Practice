class Solution {
public:
    double myPow(double x, int n) {
         long long N = n; // long long liya taaki -2^31 wala issue na ho
        if (N < 0) {
            x = 1 / x;   // agar power negative ho toh x ka reciprocal
            N = -N;
        }

        double result = 1.0;

        while (N > 0) {
            if (N % 2 == 1) {
                result *= x; // agar power odd ho toh ek x extra multiply
            }
            x *= x;          // har step pe base ko square kar do
            N /= 2;          // power ko half karte jao
        }

        return result;
    }
};