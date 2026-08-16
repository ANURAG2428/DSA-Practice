class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int maxsum = 0;
        int leftsum = 0, rightsum = 0;
        int leftindex = 0;
        // step 1 : calculate left sum till k
        for (int i = 0; i < k; i++) {
            leftsum = leftsum + v[i];
            leftindex++;
        }
        maxsum = leftsum;

        for (int i = 0; i < k; i++) {
            leftsum = leftsum - v[leftindex - i - 1];
            rightsum = rightsum + v[n - i - 1];

            maxsum = max(maxsum, rightsum + leftsum);
        }
        return maxsum;
    }
};