class Solution {
public:
    void LongestSubstring(int left, int right, int& maxlen, int& start,
                          string &str, int n) {

        // mai left tk tb tk expand kr skta hu jb tk left>=0 && right mai tb tk
        // expand kr skta hu jb tk mera right <n

        while (left >= 0 && right < n && (str[left] == str[right])) {
            // this loop conditions will helps to find longest palindromic
            // substring
            int currlen = right - left + 1;
            if (currlen > maxlen) {
                maxlen = currlen;
                start = left;
            }
            left--;  // move left
            right++; // move right
        }
}

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxlen = 0;
        for (int i = 0; i < n; i++) {
            LongestSubstring(i, i, maxlen, start, s, n);     // for odd length
            LongestSubstring(i, i + 1, maxlen, start, s, n); // for even length
        }
        // at the end sare char ke liye odd aur even length substring possible
        // case ke liye chalne ke baad maxlen and start  will help us to get
        // longest palendromic substring

        return s.substr(start, maxlen);


    }
};