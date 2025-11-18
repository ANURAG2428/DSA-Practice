class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;  // stores indexes

        // Traverse the array twice (circular)
        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];

            // Resolve all indices where current num is the next greater
            while (!st.empty() && nums[st.top()] < num) {
                result[st.top()] = num;
                st.pop();
            }

            // Only push indexes from the first iteration
            if (i < n) {
                st.push(i);
            }
        }

        return result;
    }
};
