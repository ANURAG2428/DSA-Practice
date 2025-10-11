class Solution {
public:
    // Main function that uses recursion with memoization
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);  // Initialize memoization vector with -1
        return canBreak(0, s, wordSet, memo); // Start recursion from the 0th index
    }

private:
    // Helper recursive function with memoization
    bool canBreak(int start, string& s, unordered_set<string>& wordSet, vector<int>& memo) {
        // Base case: if we've reached the end of the string, it's a valid break
        if (start == s.length()) {
            return true;
        }

        // If this index is already computed, return the result from memo
        if (memo[start] != -1) {
            return memo[start];
        }

        // Try breaking the string starting from index 'start'
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            // If the substring exists in wordSet and the rest of the string can be broken
            if (wordSet.find(word) != wordSet.end() && canBreak(end, s, wordSet, memo)) {
                return memo[start] = true; // Mark this index as valid and return true
            }
        }

        // If no valid break is found, mark this index as false
        return memo[start] = false;
    }
};