class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        // Edge case agr to n == 0 ya to 1 to hm simply return kara denege 0 ya
        // 1
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int maxOnes = 0;
        int st = 0, e = 0;
        int cntZero = 0;
        while (e < n) {
            // Step 1: Add current element
            if (v[e] == 0)
                cntZero++;

            // Step 2: Shrink if invalid
            while (cntZero > k) {
                if (v[st] == 0)
                    cntZero--;
                st++;
            }

            // Step 3: Update answer
            maxOnes = max(maxOnes, e - st + 1);

            // Step 4: Move forward
            e++;
        }
        return maxOnes;
    }
};