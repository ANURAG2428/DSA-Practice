class Solution {
public:
    bool search(vector<int>& v, int target) {
        int n = v.size();
        int s = 0, e = n-1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(v[mid] == target) return true;
            
            // Skip duplicates
            if(v[s] == v[mid] && v[mid] == v[e]) {
                s++;
                e--;
                continue;
            }
            
            if(v[s] <= v[mid]) { // left sorted
                if(v[s] <= target && target < v[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else { // right sorted
                if(v[mid] < target && target <= v[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return false;
    }
};