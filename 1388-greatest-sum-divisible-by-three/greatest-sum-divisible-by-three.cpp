class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        // dp[0] = max sum with remainder 0
        // dp[1] = max sum with remainder 1  
        // dp[2] = max sum with remainder 2
        
        for(int num : nums) {
            vector<int> temp = dp;
            for(int i = 0; i < 3; i++) {
                if(dp[i] != INT_MIN) {
                    int newRem = (i + num) % 3;
                    temp[newRem] = max(temp[newRem], dp[i] + num);
                }
            }
            dp = temp;
        }
        
        return dp[0];
    }
};