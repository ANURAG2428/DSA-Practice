class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // Step 1 : Sort the vector
        sort(nums.begin() , nums.end());
        // step 2 : print the sorted vector
        for(int i = 0; i<n ; i++){
            cout<<nums[i]<<",";
        }
        
    }
};