class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // By using Extra Space
        int n = nums.size();
        vector<int>arr(n);
        // if k is greater than n , in this case also use % operator
        k = k % n;
        for(int i = 0; i<n ; i++){
            arr[(i+k) % n] = nums[i];
        }
        
        nums = arr;
        
    }
};