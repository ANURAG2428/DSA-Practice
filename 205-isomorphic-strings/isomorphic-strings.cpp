class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        // Edge Case : if both string ki length hi same nhi hai so return false
        // kra de pehle hi
        if (n1 != n2)
            return false;
        // map 1
        unordered_map<char, char> mpp1;

        // map 2
        unordered_map<char, bool> mpp2;

        // Step 1 : will itreate till the length n1 or n2 as both are same
        for (int i = 0; i < n1; i++) {
            // Step 2 : choose both string char in each iteration
            char sChar = s[i];
            char tChar = t[i];
            // check kr ki s ka character already present hai mpp1 mai ,
            if (mpp1.find(sChar) == mpp1.end() &&
                mpp2[tChar] ==
                    false) { // here means s mpp1 mai already present nhi hai +
                             // but mujhe ye bhi check krna hai map karane se
                             // pehle ki tChar already mpp2 mai true to nhi hai
                             // -> agr hai so i cannot do below to operation
                             // each one in their respective map
                // nhi hai -> 1) so firstly store kara de in mpp1 and mpp2 mai t
                // ko
                mpp1[sChar] = tChar;
                mpp2[tChar] = true;
            } else {
                // agr hai already mpp1 mai sChar -> to ye check kr ki vo shi
                // mapped hai -> because mpp2 ka check upar wale if mai ho rakha
                // hai
                if (mpp1[sChar] != tChar) {
                    return false; // means
                }
            }
        }
        return true;
    }
};