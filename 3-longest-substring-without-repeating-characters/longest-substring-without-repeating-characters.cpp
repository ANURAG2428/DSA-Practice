class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // Edge case agr to n == 0 ya to 1 to hm simply return kara denege 0 ya
        // 1
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int maxlen = 0;
        // Step 1: sare substring generate kr using nested loop
        for (int i = 0; i < n; i++) {
            vector<int> v(256, 0); // constant size ka vector allocate kara rhe
                                   // hai for each substring where each value at
                                   // every index is initialized with 0

            // NOTE - now mai chahta hu ki kisi bhi vector ke index pai value >
            // 1 nhi honi chahiye , so iteration mai index pai value increase
            // karate hue kese karu check ki hr char jo substring ka mila hai
            // uski value at its index ==1 , not greater than 1
            for (int j = i; j < n; j++) {
                // NOTE - Here hr j loop ki iteration mai substring hi bn rhi
                // hai
                if (v[s[j]] > 0) {
                    break; // means already is character ke ascii value index
                           // pai iska cnt = 1 pehle ho chuka hai , means is
                           // substring mai ye character ek baar pehle aa chuka
                           // hai , so ye substring ko hm consider nhi kr skte
                           // to get the length of the
                           // longestNonRepeatingSubstringLength
                }
                // agr above condition true nhi hai then it means ye char pehle
                // baar aaya hai is substring mai and mai iska index pai value 1
                // kr dunga
                v[s[j]]++;
                maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};