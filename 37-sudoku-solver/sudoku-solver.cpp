class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        // Row mein check karo
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;
        }

        // Column mein check karo
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }

        // 3x3 box mein check karo
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == num) return false;
            }
        }

        return true;
    }

    bool solveSudoku(vector<vector<char>>& board) {
        // Pura board traverse karo
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Agar empty cell hai, to usmein number dalna hai
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        // Agar number safe hai to use try karo
                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num;

                            // Recursively solve karo
                            if (solveSudoku(board)) {
                                return true;
                            }

                            // Backtrack agar solution nahi mila
                            board[row][col] = '.';
                        }
                    }
                    return false; // Agar koi valid number nahi mila, to return false
                }
            }
        }
        return true; // Agar pura board fill ho gaya to return true
    }
};
