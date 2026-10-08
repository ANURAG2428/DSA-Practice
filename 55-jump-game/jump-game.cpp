class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxindex = 0;

        // step 1 : iterate through the vector , if at any point i > maxIndex
        // return false , for early breaking if (maxindex>=n-1)return true
        for (int i = 0; i < n; i++) {

            if (i > maxindex)
                return false;

            maxindex = max(maxindex , i + nums[i]);

            // early breaking , if maxindex reaches  (n-1)
            if (maxindex >= n - 1)
                return true;
        }
        return true;
    }
};