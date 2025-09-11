class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Traverse array and count break points
        for (int i = 0; i < n; i++) {
            // next index ko circular way mein lena hai
            int next = (i + 1) % n;

            // Agar current element next se bada hai, toh ek break hai
            if (nums[i] > nums[next]) {
                count++;
            }

            // Agar 1 se zyada breaks mil gaye, toh sorted rotated nahi hai
            if (count > 1) {
                return false;
            }
        }

        // Agar 0 ya 1 break mila, toh valid sorted and rotated array hai
        return true;
    }
};