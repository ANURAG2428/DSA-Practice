class Solution {
public:
    int NoofSubarraysAtmost(vector<int>& v, int n, int k) {
        int s = 0, e = 0;
        int cnt = 0;
        int distinct = 0;
        vector<int> v1(20001, 0);
        while (e < n) {
            // step 1 : appearing 1st time
            if (v1[v[e]] == 0) {
                distinct++;
            }

            // step 2 : agr normally hai tb bhi just increase no's freq in v1
            v1[v[e]]++;

            // step 3 : agr to distict > k , ya mera reache's n-1 , then
            while (distinct > k) {
                v1[v[s]]--;

                if (v1[v[s]] == 0) {
                    distinct--;
                }
                s++;
            }

            // step 4 : agr (disitinct <= k)-> cnt++
            cnt =
                cnt +
                (e - s +
                 1); // hr e pai ending subarray add kro, jisme disticnt <=k hai

            // step 5: move e forward to next iteration
            e++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& v, int k) {
        int n = v.size();
        int ans =
            NoofSubarraysAtmost(v, n, k) - NoofSubarraysAtmost(v, n, k - 1);

        return ans;
    }
};