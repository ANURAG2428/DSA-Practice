class Solution {
public:
    int SumAtMostK(vector<int>& v, int n, int k) {
        if (k < 0)
            return 0; // Edge case for (k-1) when k = 0
        int s = 0, e = 0;
        int sum = 0;
        int cnt = 0;
        while (e < n) {
            // step 1 : add element using e pointer into sum
            sum = sum + v[e];

            // step 2 : if sum>k to sum ko tb tk reduce kro jb tk vo k ke equal
            // ya u se km nhi ho jata
            while (sum > k) {
                sum = sum - v[s];
                s++;
            }

            // step 3 :  agr current iteration ka sum <= k -> to sare valid
            // subarrays ending at e pointer add kro by adding (e-s+1)
            cnt += (e - s + 1);

            // step 4 : move e pointer to the right
            e++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& v, int k) {
        int n = v.size();
        return SumAtMostK(v, n, k) - SumAtMostK(v, n, k - 1);
    }
};