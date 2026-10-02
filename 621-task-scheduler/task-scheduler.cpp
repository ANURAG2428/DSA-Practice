class Solution {
public:
    int leastInterval(vector<char>& v, int n) {

        // step 1  : store freq of each alphabet of v vector in another vector
        vector<int> freq(26, 0);
        for (auto f : v) {
            freq[f - 'A']++;
        }

        // step 2 : find the maxcount alphabet (alphabet with max frequency)
        int maxfreq = *max_element(
            freq.begin(),
            freq.end()); // * gives the value present at that iterator

        // step 3 : calculate countMax , means what all alphets in v whose freq
        // is same as maxfreq
        int countMax = 0;
        for (auto c : freq) {
            if (c == maxfreq) {
                countMax++;
            }
        }

        // step 4 : apply above variable we got in formula of Task Schedular
        int formula = (maxfreq - 1) * (n + 1) + countMax;

        // step 5 : return either Task.size() if no of alphabets are enough to
        // fill gap , else return formula (Who so ever is max , will tell which
        // case the vector is)
        return max((int)v.size(), formula);
    }
};