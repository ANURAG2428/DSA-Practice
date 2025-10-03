class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int start) {
        result.push_back(temp); // Add the current subset (temp) to result
        
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            temp.push_back(nums[i]); // Choose the current element
            backtrack(nums, result, temp, i + 1); // Recur for the next element
            temp.pop_back(); // Backtrack, remove the current element
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to easily skip duplicates
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(nums, result, temp, 0);
        return result;
        
    }
};