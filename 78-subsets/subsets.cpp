// idhr ek mujhe temp array leni padegi to get the subequnce out of num array and ek mujhe new array leni padegi to store all the subsequences in it and print it


/* 
Hum vector<vector<int>> isliye likhte hain kyunki:
Har subset ek vector<int> hota hai
Aur hume sab subsets ek saath store karne hain
Isliye hume chahiye “vector of vector of int”

 */

class Solution {
public:

void printF(int ind , vector<int>&ds , vector<vector<int>>&store, vector<int>&nums,  int n){
    if(ind == n){
        store.push_back(ds);
        return;
    }

    // sbse pehle hm element pick karenge
    ds.push_back(nums[ind]);
    printF(ind + 1 , ds , store , nums ,n);

    // not pick current element
    ds.pop_back();
    printF(ind + 1, ds ,store, nums, n);


}


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds; // temp array to form subsequence
        vector<vector<int>>store; // new array to store all subsequnce , help in printing the output
        int n = nums.size(); // size of the nums array;

        // Recursive function called
        printF(0,ds , store,nums , n); 
        
        return store;   
    }
};