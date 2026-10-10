class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Edge Case
        if (intervals.empty())
            return {};

        int n = intervals.size();

        // step 1 : to sort the intervals vector in ascending order acc to start
        sort(intervals.begin(), intervals.end());

        // step 2 : now manually push 0th index interval in result 2d vector
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        // step 3 : now iterate the intervals vector and in case of overlapping
        // merge the intervals , otherwise just simply add in result
        for (int i = 1; i < n; i++) {
            // CASE 1 : Overlap
            if (result.back()[1] >= intervals[i][0]) {
                // In case of overlap -> merge
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // simply push the interval in result vector
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};