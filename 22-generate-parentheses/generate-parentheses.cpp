class Solution {
public:
    void generate(int open, int close, int n, string current, vector<string>& result) {
    // Base case: If the current string is of length 2 * n, it's a valid combination
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    // Add an opening parenthesis if we have not used all opening parentheses
    if (open < n) {
        generate(open + 1, close, n, current + '(', result);
    }
    
    // Add a closing parenthesis if we have more open parentheses already
    if (close < open) {
        generate(open, close + 1, n, current + ')', result);
    }
}

// Main function to generate all parentheses combinations
vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(0, 0, n, "", result); // Start with empty string and 0 open/close parentheses
    return result;
}
};