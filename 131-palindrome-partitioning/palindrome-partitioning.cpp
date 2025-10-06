class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    // Backtracking function to find all possible palindrome partitions
    void backtrack(int start, const string& s, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            // Jab hum end pe pahuch jate hain, to current partition ko result mein daal dete hain
            result.push_back(current);
            return;
        }

        // Ab har possible substring check karte hain
        for (int end = start; end < s.size(); end++) {
            // Agar current substring palindrome hai
            if (isPalindrome(s, start, end)) {
                // To us substring ko current partition mein daal do
                current.push_back(s.substr(start, end - start + 1));
                // Backtrack call to find the next partition
                backtrack(end + 1, s, current, result);
                // Backtrack: Remove last element and try next substring
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;  // Final answer, containing all partitions
        vector<string> current;  // Temporary list for current partition
        backtrack(0, s, current, result);
        return result;
    }
};