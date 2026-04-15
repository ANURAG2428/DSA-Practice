class Solution {
public:
    void SwapFunc(vector<int>&nums , int n , int i , int j){
        while(i<j){
            swap(nums[i] , nums[j]);
            i++;
            j--;
        }   
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // if k is greater than  n
        k = k % n;
        if(k == 0) return; // means no need to rotate

        // Step1 : Reverse the whole array
        SwapFunc(nums , n , 0 , n-1);
        // Step 2 : Reverse the 1st k elements
        SwapFunc(nums , n , 0 , k-1 );
        // Step 3 : Reverse the last n-k elmenets
        SwapFunc(nums , n , k , n-1 );

        
    }
};