class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        // Edge case :
        if (n2 > n1) {
            return "";
        }
        int minlen = INT_MAX;
        string ans; // to store the minimum sized window
        // step 1 : create v1 for storing freq of T string character and
        // assigning count to disitnct variable storing distinct char
        vector<int> v1(256, 0);
        int distinct = 0;
        for (int i = 0; i < n2; i++) {
            if (v1[t[i]] == 0)
                distinct++;
            v1[t[i]]++;
        }

        int st = 0, e = 0;
        int matches = 0;
        int startindex = -1;
        vector<int> v2(256, 0);
        while (e < n1) {
            // step 1 : curr character ki freq v2 vector mai dalo
            v2[s[e]]++;
            // step 2 : agr curr char ki freq v1 vector mai >0 hai && dono ka
            // freq cnt same hai in v1 and v2 char then -> matches++
            if (v1[s[e]] > 0 && (v2[s[e]] == v1[s[e]])) {
                matches++;
            }

            // step 3 : jb window valid ho shrink kro
            while (matches == distinct) {
                int len = e - st + 1;
                if (len < minlen) {
                    minlen = len;
                    startindex = st;
                }

                // now left side se remove kr jb tk while loop ki condition
                // valid rehti hai
                v2[s[st]]--;
                // if mera st wala char , t mai present char tha + abhi t ke and
                // t ke vector mai uski freq jada hai as compare to s ke vector
                // mai to mai matches-- kr dunga
                if (v1[s[st]] > 0 && v2[s[st]] < v1[s[st]]) {
                    matches--;
                }
                st++;
            }

            e++;
        }
        return (startindex == -1) ? "" : s.substr(startindex, minlen);
    }
};