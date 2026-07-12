class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
    int n = v.size();
    int ans = 0;
    int p = 1, si = 0 ,ei = 0;
    while(ei<n){
        // window grow
        p = p * v[ei];
        // window shrink
        while(p>=k && si<=ei){
            p = p/v[si];
            si++;
        }
        // ans update 
        ans += (ei - si + 1);
        ei++;
    }
    return ans;
    }
};