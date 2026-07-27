class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        // Step 1: create an unordered_map
        unordered_map<char, int> mpp;
        // step 2: store each char of string with its freq in each iteration
        // using loop
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }

        // // step 3 : ab mai mpp(char, freq(int)) ko vector of size 62 mai
        // dalunga and us vector ko dec order on the basis of freq sort  dunga
        // vector<pair<char,int>>v(62);
        // // put all map element with its freq in vector
        // Step 2: Map ko vector of pairs mein daalo
        vector<pair<char, int>> v(mpp.begin(),
                                  mpp.end()); // 🔥 FIX 1: Dynamic siz

        // now ab vector mai sare {char, freq} store ho gye -> now sort them in
        // decreasing order on the basis of their freq
        sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        // now ab vector mai char with freq decreasing order mai sort hogai hai
        // -> so ab ek new string mai ye char store kara de freq wise
        string ans = "";
        for (auto& p : v) {
            // 🔥 FIX 2 & 3: Char ko 'freq' times append kar
            ans.append(p.second,
                       p.first); // C++ string constructor: append(count, char)
            // Ya manually: for(int i=0; i<p.second; i++) ans += p.first;
        }

        return ans;
    }
};