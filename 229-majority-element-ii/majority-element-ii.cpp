class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
         unordered_map<int, int> mpp;
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        mpp[v[i]]++;
        if(mpp[v[i]] > n/3 && find(ans.begin(), ans.end(), v[i]) == ans.end()) {
            ans.push_back(v[i]);
        }
    }
    return ans;
    }
};