class Solution {
public:
    int Func1(vector<int>& v, int n) {
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (v[i] > ans) {
                ans = v[i];
            }
        }
        return ans;
    }

    int Func2(vector<int>& v, int n) {
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (v[i] < ans) {
                ans = v[i];
            }
        }
        return ans;
    }

    int CheckNoofBouquet(vector<int>& v, int i, int n, int m, int k) {
        int adjacentcnt = 0;
        int Bcount = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] <= i) {
                adjacentcnt++;
                if (adjacentcnt == k) {
                    Bcount++;
                    adjacentcnt = 0; // ab dubara se adjacentcnt = 0 kr de kyoki
                                     // ab hm naya pair dhundhenge that can form
                                     // a boquet with k adjecent flower
                }
            } else {
                adjacentcnt =
                    0; // means agr vector mai present element bda nikla i se to
                       // hm adjacent elemtn  ko dubara 0 kr denge bcz it will
                       // not form adjacent flower pair and we have to look for
                       // new adjacent pair with again counting from 0
            }
        }
        return Bcount;
    }

    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();

        // Func 1 -> this will help to get min element from the array
        int maxElement = Func1(v, n);

        // Func 2 -> this will help to get max element from the array
        int minElement = Func2(v, n);

        // Step 0 : Edge Case
        if (n < (long long)m*k)return -1;

        // Step 1 : check via binary search in the range of (minElement ->to ->
        // maxElement) ->

        int s = minElement, e = maxElement;
        int result = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int ans = CheckNoofBouquet(v, mid, n, m, k);
            if (ans >= m) {
                result = mid;
                e = mid - 1; // check on left side for minDays
            } else {
                s = mid + 1;
            }
        }
        return result;
    }
};