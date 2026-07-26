class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        // Edge Case : if both string ki length hi same nhi hai so return false
        // kra de pehle hi
        if (n1 != n2)
            return false;

        // create a vector of char type which will store freq of each char
        vector<int> v(26, 0); // means declare a vector of size 26 and all
                              // element are initialized with 0

        for (int i = 0; i < n1; i++) {
            int s1 = s[i] -
                     'a'; // ye index nikal rha hai so ye int type ka hi to hoga
            v[s1]++;
            int t1 =
                t[i] -
                'a'; // // ye index nikal rha hai so ye int type ka hi to hoga
            v[t1]--;
        }

        for (int i = 0; i < 26; i++) {
            if (v[i] > 0)
                return false;
        }
        return true;
    }
};