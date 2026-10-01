class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& v1) {
        int n = v1.size();
        vector<int> v2 = v1;

        // now sort the v2 vector
        sort(v2.begin(), v2.end());

        // now store the unique elements of v2 in unordered_map with their
        // indexes
        unordered_map<int, int> mpp;
        int rank = 1;
        for (int i = 0; i < v2.size(); i++) {
            if (mpp.find(v2[i]) == mpp.end()) { // means not inserted yet in map
                mpp[v2[i]] = rank; // tabhi mai map mai dalunga with rank
                rank++;            // rank sirf new value pai badhao
            }
        }

        // now ab original v1 ko traverse kr aur v1 ke element ki jgh unki rank
        // place kr de
        for (int i = 0; i < n; i++) {
            v1[i] = mpp[v1[i]];
        }

        return v1;
    }
};