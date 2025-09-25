class Solution {
public:

    const int M = 1e9+7;
    int findpow(long long a , long long b){
        // Base Case Condition
        if(b == 0){
            return 1;
        }

        long long  half = findpow (a, b/2);
        long long  result = (half * half) % M ; // in case of even b
        
        if(b%2==1){ // means b is odd
            result = (a * result) % M;
        } 
        return result;

    }

    int countGoodNumbers(long long n) {
        return (long  long) findpow(5, (n+1)/2) * findpow(4 ,n/2) % M;
    }
};