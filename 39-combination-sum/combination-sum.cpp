

class Solution {
public:
    // Helper function to perform backtracking
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& currentCombination, vector<vector<int>>& result) {
        // Agar target 0 ho gaya, toh current combination ko result mein add kar do
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        
        // Loop through candidates and try each one
        for (int i = start; i < candidates.size(); i++) {
            // Agar current candidate target se zyada hai, toh break kar dena
            if (candidates[i] > target) break;
            
            // Include current candidate and recursively call for the next target
            currentCombination.push_back(candidates[i]);
            backtrack(i, target - candidates[i], candidates, currentCombination, result);
            // Backtrack: remove the last added element
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        // Sort candidates to make sure we can break early if needed
        sort(candidates.begin(), candidates.end());
        
        // Start backtracking from index 0
        backtrack(0, target, candidates, currentCombination, result);
        
        return result;
    }
};