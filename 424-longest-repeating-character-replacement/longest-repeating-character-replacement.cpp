class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int st = 0, e = 0;
        int maxfreq = 0;
        vector<int> freq(26, 0);
        while (e < n) {
            // step 1: store current e char in freq vector
            freq[s[e] - 'A']++;
            // step 2: select the cnt of maxfreq char
            maxfreq = max(maxfreq, freq[s[e] - 'A']);

            // step 3: incase mera logic shi nhi hai so
            while ((e - st + 1) - maxfreq > k) {
                freq[s[st] - 'A']--;
                st++;
            }

            // step 4 : ab mene upar wala case jo ki substring ko invalid kr
            // deta to be the longest repeating char substring usko fix kr diya
            // , so now ab iske baad hr case ye logic follow kr rha hai logic :
            // ((e-st+1) - maxfreq <=k) -> so ab ye hamesha follow hoga so no
            // need to write it
            maxlen = max(maxlen, e - st + 1);

            // step 5 : hr iteration mai ko aage badayenge outer while loop ke
            e++;
        }
        return maxlen;
    }
};