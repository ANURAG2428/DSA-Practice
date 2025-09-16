class Solution {
public:
     int mod = 1e9 + 7;
    
    long long power(long long x, long long y) {
        long long res = 1;
        x %= mod;
        
        while(y > 0) {
            if(y & 1) {
                res = (res * x) % mod;
            }
            y >>= 1;
            x = (x * x) % mod;
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2; // Even indices count
        long long odd_count = n / 2;         // Odd indices count
        
        long long even_ways = power(5, even_count);
        long long odd_ways = power(4, odd_count);
        
        return (even_ways * odd_ways) % mod;
        
    }
};