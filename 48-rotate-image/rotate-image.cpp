class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // matrix ka size lena hai, n x n

        // Step 1: Transpose the matrix (rows ko columns me convert karna)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap matrix[i][j] with matrix[j][i]
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            // Row ko reverse karenge
            while (left < right) {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};