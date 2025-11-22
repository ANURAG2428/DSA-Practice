class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        // here if have to return the minimum no of operations to make all elements of nums divisible by 3
        // Note - yaha mujhe no operation return krne hai kese 3 se divisble kareynege uski fikar nhi krni hai

        for(auto num : nums){
            if(num % 3 == 1) cnt++; // means mujhe ek operation perform krna hai that is substract (-1)
            else if (num % 3 == 2) cnt++; // means mujhe ek operation perform krna hai that is substract (+1)
            // if(num % 3 == 0) , means i don't need any operation
        }
        return cnt;
    }
};