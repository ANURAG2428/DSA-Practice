
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // Rows ki count
        int n = matrix[0].size();     // Columns ki count

        bool firstRowZero = false;    // First row me agar zero hai to track karna hai
        bool firstColZero = false;    // First column me agar zero hai to track karna hai

        // Check if the first row has any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column has any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Ab hum baaki matrix ko check karenge
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // Row ko mark karenge
                    matrix[0][j] = 0;  // Column ko mark karenge
                }
            }
        }

        // Use marks to set the zeroes in the matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};