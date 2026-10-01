class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return {};

        // Step 1: (value, originalIndex) pairs banao
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {arr[i], i};
        }

        // Step 2: sort by value
        sort(v.begin(), v.end());

        // Step 3: ranks assign karo
        vector<int> result(n);
        int rank = 1;

        result[v[0].second] = rank; // pehla element

        for (int i = 1; i < n; i++) {
            if (v[i].first != v[i - 1].first) {
                rank++; // naya value → rank badhao
            }
            result[v[i].second] = rank;
        }

        return result;
    }
};