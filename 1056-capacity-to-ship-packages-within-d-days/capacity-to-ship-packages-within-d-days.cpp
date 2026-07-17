class Solution {
public:
    int CheckLeastCapacity(vector<int>& v, int i, int d, int n) {
        int sum = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            sum = sum + v[j];
            if (sum == i) { // ya to sum equal ho skta hai capcaity ke
                cnt++;
                sum = 0;
            } else if (sum > i) { // ya to sum bda ho skta hai capcaity se
                sum = 0;
                cnt++;
                j--;
            }
        }

        // Check if at the end sum is greater than 0 means some weight is there
        // so i will increase the cnt
        if (sum > 0)
            cnt++;

        if (cnt <= d) {
            return i;
        } else {
            return -1;
        }
    }

    int shipWithinDays(vector<int>& v, int d) {
        int n = v.size();
        // Step 1: we will set range/ search space will be from MaxElement to
        // sum of vector
        int VectorSum = accumulate(v.begin(), v.end(), 0);
        int maxElement = *max_element(v.begin(), v.end());

        int ans = -1;
        int s = maxElement, e = VectorSum;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int result = CheckLeastCapacity(v, mid, d, n);
            if (result != -1) {
                ans = mid;
                e = mid - 1; // will look in left side for least weight capcity
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};