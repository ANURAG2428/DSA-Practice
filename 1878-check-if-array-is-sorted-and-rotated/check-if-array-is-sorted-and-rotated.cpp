class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        if(n<=1) return true;

        for(int i = 0; i<n ; i++){
            // Circular check last element se first element tk 
            if(nums[i] > nums[(i+1) % n]){
                cnt++;
            }
        }

        if(cnt <= 1){
            return true;
        }
        return false;
    }
};