class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Mapping digits to letters
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        
        // Agar digits empty hai to return empty result
        if (digits.empty()) return result;
        
        // Helper function for backtracking
        backtrack(result, digits, mapping, "", 0);
        
        return result;
    }
    
    // Backtracking function to generate all combinations
    void backtrack(vector<string>& result, const string& digits, const vector<string>& mapping, string current, int index) {
        // Agar humne saare digits process kar liye hain, to current combination ko result mein add karte hain
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        // Current digit se associated letters ko iterate karte hain
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            // Har letter ke liye backtrack call karte hain
            backtrack(result, digits, mapping, current + letter, index + 1);
        }
    }
};