class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // Edge case agr to n == 0 ya to 1 to hm simply return kara denege 0 ya
        // 1
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int maxlen = 0;
        int st = 0, e = 0;
        vector<int> v(256, 0);
        while (e < n) {
            while(v[s[e]] >=
                1) { // means mere current substring mai dupicate element hai
                v[s[st]]--;
                st++;
            }
            v[s[e]]++;
            maxlen = max(maxlen, e - st + 1);
            e++;
        }
        return maxlen;
    }
};