class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        // Edge Case : if no string present in vector return " " -> as asked in
        // que
        if (s.empty())
            return "";

        // step 1 : 0th index string ko as as outer loop lele
        for (int i = 0; i < s[0].size(); i++) {
            // step 3 : take ith character each time to check and compare the
            // condition
            char character = s[0][i];
            // inner loop
            for (int j = 1; j < s.size(); j++) {
                if (i == s[j].size() || character != s[j][i]) {
                    return s[0].substr(0, i);
                }
            }
        }

        // if sare character of all string got exactly matched with 0th index
        // string -> so will return whole 0th string
        return s[0];
    }
};