class Solution {
public:
    bool isNStraightHand(vector<int>& v, int grpsize) {
        int n = v.size();

        // step 1 : sbse pehle to store all no's freq into a map (ordered-map)
        map<int, int> mpp;
        for (auto x : v) {
            mpp[x]++;
        }

        // step 2 : lets ab khud ka ek variable start banata hu which will
        // initially points to the smalles element of v and then further using
        // loop usse aage iterate krata jaunga to form a batch of grpsize , the
        // moment the consecutive element of grp not found will return false

        // run a while loop till map is not empty
        while (!mpp.empty()) {
            // taking smallest element for each batch to form it into a grp of
            // size grpsize
            int start = mpp.begin()->first; // accessing value

            // running a inner loop which will check
            for (int i = 0; i < grpsize; i++) {
                int curr =
                    start +
                    i; // adding i will help in getting next consecutive card ,
                       // with the help of this we can check weather the
                       // consecutive element present in the mp , if not or
                       // mpp[curr] == 0  then return false

                if (mpp.find(curr) == mpp.end() || mpp[curr] == 0) {
                    return false;
                }

                // decerase freq of curr
                mpp[curr]--;
                // if freq of curr ==0 , remove that from map
                if (mpp[curr] == 0)
                    mpp.erase(curr);
            }
        }
        return true;
    }
};