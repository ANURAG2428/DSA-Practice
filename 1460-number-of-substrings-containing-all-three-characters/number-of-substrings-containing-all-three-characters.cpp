class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;

        int v[3] = {-1, -1, -1}; // each value is initialized with -1 , as we
                                 // have to store index in array element
        int distinct = 0;
        int minIndex = INT_MAX;
        for (int i = 0; i < n; i++) {

            int indx = s[i] - 'a'; // position/index find krna

            if (v[indx] == -1)
                distinct++; // means 1st time ye char aaya hai iteration mai ,
                            // not present in v array before

            v[indx] = i; // curr char ko array mai curr iteration index i se
                         // assign kr diya

            // find min index char from the array storing indexe's
            // minIndex = min({v[0] , v[1] , v[2]});
            // or
            minIndex = min(v[0], min(v[1], v[2]));

            if (distinct == 3) {
                cnt = cnt + (minIndex + 1);
            }
        }

        return cnt;
    }
};