class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newinterval) {
        int n = intervals.size();

        // Note - no need to sort the array ,as given array is alreeady sorted
        // in ascending order according to "start"
        vector<vector<int>> result; // will store newadded interval in this new
                                    // result 2d vector along with old intervals

        // step 1 : sbse pehle jo interval chote hai from newinterval unko
        // result mai add krde
        int i = 0;
        while (i < n && intervals[i][1] < newinterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Step 2 : now ab agr incase intervals overlap kr rhe hai ya new added
        // interval ko add krna hai chahe overlap na bhi kr rhe ho , lets see
        // kese karenge
        while (i < n && intervals[i][0] <= newinterval[1]) {
            newinterval[0] = min(newinterval[0], intervals[i][0]);
            newinterval[1] = max(newinterval[1], intervals[i][1]);
            i++;
        }
        // below statement will work when mera interval[i][1] < newinterval[0]
        // -> can't execute further , and above 2nd while loop bhi nhi chla due
        // to non-overlapping interval. So below statement simply add the new
        // interval in result vector . now below ab right pending interval add
        // ho jayenge in result vector
        result.push_back(newinterval);

        // Step 3 : now ab right side of new intervals mai jo pending interval
        // hai unko result vector mai add krod
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};