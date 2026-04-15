class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int i = 0;
        int j = i + 1;
        while(i<n-1 && j<n){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            
            }
            j++;
        }

        return (i + 1);
    }
};