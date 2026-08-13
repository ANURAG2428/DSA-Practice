class Solution {
public:
    long long NoOfSubstringWithAtMost2Char(string s, int n) {
        long long cnt = 0;
        int st = 0, e = 0;
        int distinct = 0;
        vector<int> v(3, 0);
        while (e < n) {
            int indx = s[e] - 'a'; // e pointer pai present character
            // step 1 : sbse pehle check kr curr char vector mai 1st time aarha
            // hai -> agr aarha hai to disticnt++ kr de
            if (v[indx] == 0) {
                distinct++;
            }

            // step 2 : ab curr char ka cnt vect mai bda de
            v[indx]++;

            // step 3 : agr disticnt == 3 means 3 chr aagye hai is particular
            // substring mai
            while (distinct == 3) {
                int indxs =
                    s[st] - 'a'; // starting pointer pai present character
                v[indxs]--;      // as v stores the cnt of char a,b,c at their
                                 // particular indexes
                if (v[indxs] == 0) {
                    distinct--;
                }
                st++;
            }

            // in case of substring having <=2 char will add it into cnt
            if (distinct <= 2) {
                cnt = cnt + (e - st + 1);
            }

            e++;
        }

        return cnt;
    }

    int numberOfSubstrings(string s) {
        long long n = s.size();
        long long total = n * (n + 1) / 2;
        long long ans = total - NoOfSubstringWithAtMost2Char(s, n);

        return (int)ans;
    }
};