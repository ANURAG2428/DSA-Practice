class Solution {
public:
    int findMin(vector<int>& v) {
        int minElement = INT_MAX;
        int n = v.size();
        int s = 0 , e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            minElement = min(minElement , v[mid]);
            // check for the sorted portion in left part
            if(v[s] <= v[mid]){  // means this is sorted portion
                minElement = min(minElement , v[s]);
                s = mid + 1;
            }
            // but agr esa nhi hai
            else{
                minElement = min(minElement , v[e]);
                e = mid - 1;
            }

        }
        return minElement;
    }
};