class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Here simply i will use Two pointer approch
        int n = nums.size();
        int i = 0;
        int j = i+1;
        while(i< n-1 && j <n){
            if(nums[i] == 0 && nums[j]!= 0){
                swap(nums[i], nums[j]);
                i++;
            }
            else if(nums[i] != 0){
                i++;
            }
            j++;
        }
        
    }
};