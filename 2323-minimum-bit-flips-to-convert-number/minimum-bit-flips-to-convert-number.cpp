class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;

        int cnt = 0;
        // apply count function for calculating set bit in ans
        while(ans!=0){
            ans = ans & (ans-1);
            cnt = cnt + 1; 

        }
        return cnt;
        
    }
};