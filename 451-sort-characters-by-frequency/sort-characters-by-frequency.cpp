class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        // Step 1:create a vector of size 128
        vector<int> freq(128, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i]]++; // so it will increase the count at s[i] index means
                          // if s[i] = 'a' -> so a in int is 97 ASCII value , so
                          // it will increase freq count there
        }

        // Step 2 : ab mai ek vector banaunga of pair type consisting of char ,
        // int -> which will store freq of each char in each itreation
        vector<pair<char, int>> v;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 0) { // means element present
                // now put the char and freq in this pair vector v
                v.push_back({(char)i, freq[i]});

                // or we can also write it as , below
                /*
                pair<char,int> p;

                p.first = (char)i;
                p.second = freq[i];

                v.push_back(p);
                */
            }
        }

        // now ab vector mai sare {char, freq} store ho gye -> now sort them in
        // decreasing order on the basis of their freq
        sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        // now ab vector mai char with freq decreasing order mai sort hogai hai
        // -> so ab ek new string mai ye char store kara de freq wise
        string ans = "";
        for (auto& p : v) {

            ans.append(p.second,
                       p.first); // C++ string constructor: append(count, char)
            // Ya manually: for(int i=0; i<p.second; i++) ans += p.first;
        }

        return ans;
    }
};