class Solution {
public:
    // Custom comprator to sort the vector on the basis of second in ascending
    // order
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // step 0 : Edge Case
        if (intervals.empty())
            return 0;

        // step 1 : is to sort the vector on the basis of pair.second
        sort(intervals.begin(), intervals.end(), cmp);

        // step 2 : ab simply iterate kar through intervals vector
        int cnt = 0, lastelement = INT_MIN;
        for (auto& time : intervals) {
            int start = time[0];
            int end = time[1];
            if (start >= lastelement) { // as given in question to include the
                                        // eqaul to condition as well
                cnt++;
                lastelement = end;
            }
        }

        return intervals.size() - cnt;
    }
};