class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int n = v.size();
        int s = 0, e = n - 1; // indexs liye hai starting and ending pointer mai
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int result =
                v[mid] - (mid + 1); // check for no of  missing no before this
                                    // index -> if missing no are less then k ->
                                    // look at right -> else look at left
            if (result < k) {       // look at right side by s = mid + 1
                s = mid + 1;
            } else { // agr kisi index pai missing no jada hai as compare to k
                     // look at left side
                e = mid - 1;
            }
        }
        // loop breaks -> due to opposite polarity -> (s>e) -> here we can
        // return kth missing no by [(high+1) + k]  or [low + k]
        return s + k;
    }
};