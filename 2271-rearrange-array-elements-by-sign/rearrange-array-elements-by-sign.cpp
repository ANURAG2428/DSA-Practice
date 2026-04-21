class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n = v.size();
            // STEP 1 : ans vector mai mai req rearrangement mai element store karunga from input vector
        vector<int>ans(n); 

        // STEP 2 : Simply mai iterate karunga over input array and store karunga positive and negative element on their suitable index
        int pos = 0 , neg = 1 ; // kyoki yhi order hoga
        
        // STEP 3 : store correct element at correct index
        for(int i = 0 ; i<n ; i++){
            if(v[i] > 0){
                ans[pos] = v[i];
                pos = pos + 2;
            }
            else{
                ans[neg] = v[i];
                neg = neg + 2;
            }
        }
        return ans;
    }
};