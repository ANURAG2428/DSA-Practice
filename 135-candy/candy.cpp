class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();

        int sum = 1; // for 0th index element we given 1 candy to the 0th index
                     // element

        int i = 1; // iterator starting from 1st index

        // IMP = here we are iterating rating vector only 1 time
        while (i < n) {
            // step 1 : agr rating[i] == rating[i-1] -> means sum mai  + 1 add
            // karo , kyoki same no of candies milengi same rating walo ko
            if (rating[i] == rating[i - 1]) {
                sum += 1;
                i++;      // move to next iteration
                continue; // and no need to proceed further for this iteration ,
                          // move to next iteration (simply skip this iteration
                          // )
            }

            int peak = 1; // intializing candy count for increasing rating trend
                          // // hmeash hr rating ko atleast 1 candy to milegi hi

            while (i < n && rating[i] > rating[i - 1]) {

                peak += 1;   // peak gets increase , as inc
                sum += peak; // now peak will get added to sum , bcz peak
                             // representing the no of candy this rating should
                             // get , which will get added to sum

                i++; // moving to next iteration
            }

            int down = 1; // now decreasing slope ke time bhi hr rating pai
                          // atleast 1 candy to hogi hi

            while (i < n && rating[i] < rating[i - 1]) {

                sum += down;
                i++;       // will move to next iteration
                down += 1; // down on decrasing slope get inc by 1 , which will
                           // get added to sum further
            }

            // Now if (down > peak) , then down-peak => get added to sum
            if (down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
};