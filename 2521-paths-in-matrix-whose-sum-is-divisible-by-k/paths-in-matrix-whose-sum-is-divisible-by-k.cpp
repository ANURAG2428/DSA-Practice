class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        // Base case: starting cell
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                
                for (int rem = 0; rem < k; rem++) {
                    if (i > 0) {
                        int newRem = (rem + val) % k;
                        dp[i][j][newRem] = (dp[i][j][newRem] + dp[i - 1][j][rem]) % MOD;
                    }
                    if (j > 0) {
                        int newRem = (rem + val) % k;
                        dp[i][j][newRem] = (dp[i][j][newRem] + dp[i][j - 1][rem]) % MOD;
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1][0];
    }
};