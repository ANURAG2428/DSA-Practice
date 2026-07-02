class Solution {
public:
    int search(vector<int>& v, int target) {
    int n = v.size();
    int s = 0 , e = n-1;
    int indx = -1;
    while(s<=e){
        // Step 1 : calculate mid
        int mid = s + (e-s)/2;
        // step 2 : check konsa search space sorted hai
        if(v[mid] == target){   // CASE 1
            indx = mid;
            return indx;
        }

        // LEFT PORTION SORTED
        if(v[s]<=v[mid]){        // CASE 2  (left search space is sorted) 
            // check if target is between this left search space
            if(v[s] <= target && target <= v[mid]){
                e = mid - 1;  // target left side mai hai
            } 
            else{
                s = mid + 1;  // target right side mai hai
            }
        }

        // RIGHT PORTION IS SORTED
        else{               // CASE 3    (Right search space is sorted)
            if(v[mid]<= target && target <= v[e]){
                s = mid + 1;  // target right side mai hai
            }
            else{
                e = mid -1;  // target left side mai hai 
            }
            
        } 
    }
    return -1;

        
    }
};