class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        // step 1 : sbse pehle to nums vector ke sare element ko ek new string
        // vector mai daal de
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            v[i] =
                to_string(nums[i]); // nums array mai integer element hai to mai
                                    // -> v vector jo ki string hai usme nums ke
                                    // element string mai convert krke dalunag
        }

        string ans = "";

        // sort the vector using custom comprator
        sort(v.begin(), v.end(),
             [](string& a, string& b) { return a + b > b + a; });

        // now ab v mai jis order mai element arranged hai unhe concatenate kra
        // ke ans mai store kra de
        for (int i = 0; i < n; i++) {
            ans = ans + v[i];
        }

        if (ans[0] == '0')
            return "0";
        return ans;
    }
};