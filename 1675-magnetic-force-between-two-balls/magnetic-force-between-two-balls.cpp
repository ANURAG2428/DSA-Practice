class Solution {
public:
    bool CheckCowsArrangment(vector<int>& v, int n, int cows, int i) {
        int cntCows =
            1; // by default 1st cow to hamesha 0th index pai place hogi , tabhi
               // hm hr cow ka distance calculate kr payenge
        int lastPos = v[0];

        // loop over vector to see for min distance 'i' can we place k cows
        // effectively
        for (int j = 1; j < n; j++) {
            if (v[j] - lastPos >= i) {
                cntCows++;
                lastPos = v[j];
            }
            if (cntCows >= cows) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& v, int cows) {
        int n = v.size();
        // Step 1 : sort the given vector
        sort(v.begin(), v.end()); // T.C = O(nlogn)

        // Step 2: ab 1 se leke (max-min)Element Range tk loop chala to get all
        // the possible min distance for which we can place k cows in stalls
        int s = 1, e = (v[n - 1] - v[0]);
        while (s <= e) {
            int mid = s + (e - s) / 2;
            bool result = CheckCowsArrangment(v, n, cows, mid);
            if (result) { // means is mid ke liye we got the arrangement , means
                          // this mid distance can make k cows arranged
                          // succesfully in array
                s = mid + 1; // will move to right
            } else {
                e = mid -
                    1; // will move to left (if we can't able to arrange the
                       // cows for the mid ,means we need smaller distance )
            }
        }
        if (s > e)
            return e;
        else
            return -1;
    }
};