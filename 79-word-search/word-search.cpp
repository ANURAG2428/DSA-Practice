class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Size of board
        int m = board.size();
        int n = board[0].size();
        
        // Function for DFS search
        function<bool(int, int, int)> dfs = [&](int i, int j, int index) -> bool {
            // Base case: If the index reached the length of word, return true
            if (index == word.size()) return true;
            
            // Check if out of bounds or if current cell doesn't match the current word character
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
                return false;
            }
            
            // Temporarily mark the board cell as visited
            char temp = board[i][j];
            board[i][j] = '#';
            
            // Explore the four directions: up, down, left, right
            bool found = dfs(i + 1, j, index + 1) || dfs(i - 1, j, index + 1) ||
                         dfs(i, j + 1, index + 1) || dfs(i, j - 1, index + 1);
            
            // Restore the cell value after the exploration
            board[i][j] = temp;
            
            return found;
        };

        // Iterate over each cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start DFS from every cell
                if (board[i][j] == word[0] && dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false; // If no word found
    }
};