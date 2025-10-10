class Solution {
public:
    // Helper function to check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check the column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    // Backtracking function to solve the N-Queens problem
    void solveNQueens(int row, vector<string>& board, vector<vector<string>>& result, int n) {
        if (row == n) {
            result.push_back(board); // All queens are placed, so add the board to result
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; // Place the queen
                solveNQueens(row + 1, board, result, n); // Recursively place queens in next row
                board[row][col] = '.'; // Backtrack, remove the queen
            }
        }
    }

    // Main function to solve the N-Queens problem and return all possible solutions
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); // Initialize an empty board with '.'

        solveNQueens(0, board, result, n); // Start from the first row
        return result;
    }
};