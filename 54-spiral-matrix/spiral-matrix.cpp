class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        int sr = 0, er = n - 1;
        int sc = 0, ec = m - 1;
        
        while(sr <= er && sc <= ec) {
            // 1. Print top row (sr, sc to ec)
            for(int col = sc; col <= ec; col++) {
                ans.push_back(matrix[sr][col]);
            }
            sr++;
            
            // 2. Print right column (sr to er, ec)
            for(int row = sr; row <= er; row++) {
                ans.push_back(matrix[row][ec]);
            }
            ec--;
            
            // 3. Print bottom row (er, ec to sc) - only if sr <= er
            if(sr <= er) {
                for(int col = ec; col >= sc; col--) {
                    ans.push_back(matrix[er][col]);
                }
                er--;
            }
            
            // 4. Print left column (er to sr, sc) - only if sc <= ec
            if(sc <= ec) {
                for(int row = er; row >= sr; row--) {
                    ans.push_back(matrix[row][sc]);
                }
                sc++;
            }
        }
        
        return ans;
    }
};