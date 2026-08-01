class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            vector<int> v(26, 0);
            for (int j = i; j < n; j++) {
                // ab simply jo bhi j index pai char hai usse freq vector mai
                // uska count daal de
                v[s[j] - 'a']++;
                int maxfreq = 0, minfreq = INT_MAX;
                // ab v of size 26 vector ko pura iterate kr and jo bhi maxfreq
                // and min freq ki value mille unhe minus krke sum mai add krde
                for (int k = 0; k < 26; k++) {
                    if (v[k] > 0) {
                        maxfreq = max(maxfreq, v[k]);
                        minfreq = min(minfreq, v[k]);
                    }
                }
                sum = sum + (maxfreq - minfreq); // beauty add kro
            }
        }
        return sum;
    }
};