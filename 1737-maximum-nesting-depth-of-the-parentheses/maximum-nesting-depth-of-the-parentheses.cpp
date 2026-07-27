class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int cnt = 0, maxcnt = 0; // in case paranthesis string mai exist hi nhi
                                 // krta then maxcnt would be = 0

        // Edge case : if string length is 0
        if (n == 0)
            return maxcnt;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            } else if (s[i] == ')') {
                cnt--;
            }
        }
        return maxcnt;
    }
};