
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; // Final answer yahan store karenge

        if (matrix.empty()) return ans; // Agar matrix khali hai, to return kar do

        int top = 0;                     // Upar wali boundary
        int bottom = matrix.size() - 1;  // Neeche wali boundary
        int left = 0;                    // Left boundary
        int right = matrix[0].size() - 1;// Right boundary

        // Jab tak sab boundaries valid hain
        while (top <= bottom && left <= right) {

            // Step 1: Left se Right move karna (Top row)
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++; // Top row ka kaam ho gaya, ab niche move karenge

            // Step 2: Top se Bottom move karna (Right column)
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Right column ka kaam ho gaya, ab left side aayenge

            // Step 3: Right se Left move karna (Bottom row)
            if (top <= bottom) { // Check zaruri hai, warna duplicate add ho sakte hain
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--; // Bottom row complete ho gayi
            }

            // Step 4: Bottom se Top move karna (Left column)
            if (left <= right) { // Check zaruri hai
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Left column complete ho gaya
            }
        }

        return ans;
    }
};