/* 
Time Complexity: O(log n) 

Space Complexity: O(log n)
*/


class Solution {
public:
    
    double solve(double x, long long n) {
        // ye hogya mera edge case condition + B.C.C
        if(n == 0)
            return 1;
        
        if(n < 0)
            return solve(1/x, -n);
        
        
        if(n%2 == 0) {
            return solve(x*x, n/2);
        }
        
        return x*solve(x*x, (n-1)/2);
        
    }
    
    double myPow(double x, int n) {
        return solve(x, (long long)n);
    }
};