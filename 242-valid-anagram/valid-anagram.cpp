class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int n2 = t.size();
        vector<int>hashvec(26 , 0);

        for(int i = 0 ; i< n ; i++){
            hashvec[s[i] - 'a']++;
        }

        // now t string iterate kr agr hashvec pura 0 hogya means its a anagram
        for(int i = 0; i<n2 ; i++){
            hashvec[t[i] - 'a']--;
        }

        for(int i = 0; i<26 ; i++){
            if(hashvec[i] != 0){
                return false;
            }
        }
        return true;
    }
};