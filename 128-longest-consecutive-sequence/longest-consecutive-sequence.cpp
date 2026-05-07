class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;
        
        for(int num : s) {
            // Check if current number is the START of a sequence
            if(s.find(num - 1) == s.end()) {
                int currentNum = num;
                int length = 1;
                
                while(s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    length++;
                }
                
                longest = max(longest, length);
            }
        }
        
        return longest;
    }
};