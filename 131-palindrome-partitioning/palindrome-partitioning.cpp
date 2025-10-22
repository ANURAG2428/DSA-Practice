class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }

    void func(int index, string s, vector<string> &path, vector<vector<string>> &res) {
        // Base Case
        if(index == s.size()) {
            res.push_back(path);  // ✅ Store valid partition
            return;
        }

        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {  // Check substring s[index..i]
                // Take this palindrome substring
                path.push_back(s.substr(index, i - index + 1));
                
                // Recursive call from NEXT position
                func(i + 1, s, path, res);
                
                // Backtrack
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};