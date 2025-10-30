class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);  // -1: not computed
        return solve(0, s, dict, memo);
    }
    
    bool solve(int index, string &s, unordered_set<string> &dict, vector<int> &memo) {
        if(index == s.length()) return true;
        
        // ✅ MEMOIZATION CHECK
        if(memo[index] != -1) return memo[index];
        
        for(int end = index; end < s.length(); end++) {
            string word = s.substr(index, end - index + 1);
            if(dict.count(word)) {
                if(solve(end + 1, s, dict, memo)) {
                    return memo[index] = true;  // ✅ MEMOIZATION STORE
                }
            }
        }
        
        return memo[index] = false;  // ✅ MEMOIZATION STORE
    }
};