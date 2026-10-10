class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        // Edge case
        if (intervals.empty())
            return 0;

        // step 1 : sort the intervals 2d array acc to start in ascending order
        sort(intervals.begin(), intervals.end());

        // step 2 : now make min-heap priority_queue and push 0th index end in
        // it
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(intervals[0][1]);

        // step 3 : now iterate intervals vector from 1st index to n-1 and we
        // know if-else condition
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int mini = pq.top();

            if (start <= mini) {
                // as it will cause same interval collison , so will it into pq
                // as another grp
                pq.push(end);
            } else {
                // here , intervals are not colliding , so no need to add it as
                // seprate , grp will simply update min's end by the largest end
                // .NOTE - but this will chaneg the local copy , not the
                // original heap , so to change original heap will pop the top
                // of pq and will add current intervals end , bcz if current
                // intervals start > pq.top() , so end to bda hoga hi obvious
                // hai
                pq.pop();
                pq.push(end);
            }
        }

        return pq.size(); // this will return total no of grp containing
                          // intervals , where ther is no overlapping
    }
};