class Solution {
public:
    // Helper function to perform backtracking
    void findCombinations(int idx, int target, vector<int>& candidates, vector<int>& currentCombo, vector<vector<int>>& result) {
        // Base case: if target is 0, we found a valid combination
        if (target == 0) {
            result.push_back(currentCombo);
            return;
        }

        // Loop through the candidates starting from index 'idx'
        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates by ensuring we're not considering the same element again
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            
            // If the current candidate exceeds the target, no need to continue
            if (candidates[i] > target) break;

            // Choose the current number and recurse with the reduced target
            currentCombo.push_back(candidates[i]);

            // Recursive call to find next elements, moving index forward
            findCombinations(i + 1, target - candidates[i], candidates, currentCombo, result);

            // Backtrack: remove the last element and try the next candidate
            currentCombo.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombo;

        // Sort the candidates array to handle duplicates and stop early when needed
        sort(candidates.begin(), candidates.end());

        // Start backtracking from index 0
        findCombinations(0, target, candidates, currentCombo, result);

        return result;
    }
};
