class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // STEP 1 : Create 3 pointer -> low , mid , high
        int low = 0 , mid = 0 , high = n-1;
        
        // Step 2 : While loop likh till (mid<high)
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }
            else if( nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        }
        for(int i = 0 ; i<n ; i++){
            cout<<nums[i]<<",";
        }
    }
};