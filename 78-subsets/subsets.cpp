class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int start) {
        // Add current subset to the result
        result.push_back(current);
        
        // Explore further elements to include in the current subset
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, current, result, i + 1); // move to the next element
            current.pop_back(); // Backtrack, remove the last element
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, current, result, 0); // start from the first element
        return result;
    }
};