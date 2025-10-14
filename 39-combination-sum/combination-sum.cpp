class Solution {
public:
    // Function to find all combinations
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: when the target becomes 0, add the current combination to result
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // If the target is less than 0, no point in continuing
        if (target < 0) {
            return;
        }
        
        // Iterate through the candidates starting from 'start' index to allow duplicates
        for (int i = start; i < candidates.size(); ++i) {
            // Add the current candidate to the current combination
            current.push_back(candidates[i]);
            // Recursively call backtrack with reduced target and the same start index (allowing repetition)
            backtrack(i, target - candidates[i], candidates, current, result);
            // Backtrack: remove the last added element
            current.pop_back();
        }
    }

    // Main function to solve the problem
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }
};