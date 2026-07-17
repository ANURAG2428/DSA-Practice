class Solution {
public:
    int CheckdivisonSum(vector<int>& v, int i, int t, int n) {
        int sum = 0;
        int res = 0;
        for (int j = 0; j < n; j++) {
            res = (v[j] + i - 1) / i;
            sum = sum + res;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& v, int t) {
        int n = v.size();
        // Step 1 : find max element from vector to create search space
        int maxElement = *max_element(v.begin(), v.end()); // T.C = o(1)

        int ans = -1;
        // Step 2 : will use binary search , so we will create a search space
        // from 1 to maxElement . Where i will look for the smallest divisor
        int s = 1, e = maxElement;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int result = CheckdivisonSum(v, mid, t, n);
            if (result <=
                t) { // will store this result in ans and will look in left
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};