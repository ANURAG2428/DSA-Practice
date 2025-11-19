class Solution {
public:
    int singleNumber(vector<int>& nums) {
           int ones = 0, twos = 0;
    
    for(int num : nums) {
        // Step 1: Update 'ones'
        // XOR with num: agar bit pehli baar aayi toh ones mein set ho
        // & ~twos: ensure ki jo bit already twos mein hai, wo ones mein na aaye
        ones = (ones ^ num) & ~twos;
        
        // Step 2: Update 'twos' 
        // XOR with num: agar bit dusri baar aayi toh twos mein set ho
        // & ~ones: ensure ki jo bit ones mein set ho gayi, wo twos mein na aaye
        twos = (twos ^ num) & ~ones;
    }
    
    return ones; // Final answer ones mein hoga
    }
};