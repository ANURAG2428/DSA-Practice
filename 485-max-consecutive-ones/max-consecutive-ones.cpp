class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxcnt = 0;
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(nums[i] == 1){
                cnt++;
                maxcnt = max(maxcnt , cnt);
            }
            else{ // nums[i] == 0 , simply turn cnt to 0
                cnt = 0;
            }
        }
        return maxcnt;
    }
};