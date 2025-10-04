class Solution {
public:
    // Final result store karne ke liye
    vector<vector<int>> result;

    // Backtracking function
    void backtrack(int k, int n, int start, vector<int>& current) {
        // Base case: agar k numbers le liye aur sum bhi match ho gaya
        if (k == 0 && n == 0) {
            result.push_back(current);
            return;
        }

        // Agar k ya n negative ho gaya, to aage jaane ka koi matlab nahi
        if (k < 0 || n < 0) return;

        // 1 se 9 tak ke numbers try karo
        for (int i = start; i <= 9; i++) {
            current.push_back(i);       // current number add karo
            backtrack(k - 1, n - i, i + 1, current); // next number ke liye call
            current.pop_back();         // backtrack (number hata do)
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        backtrack(k, n, 1, current);
        return result;
    }
};
