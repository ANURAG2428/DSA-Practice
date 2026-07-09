class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size();
        // Edge Case : Array is of size 1 then -> will simply return 0th index
        if(n == 1) return 0;
        // Step 1 : check of 1st element and last element -> as if any of them is peak element -> it would save us from finding it via BS
        if(v[0] > v[1]) return 0;
        if(v[n-1] > v[n-2]) return n-1;

        // Step 2 : now check for the remaining element of array -> in case first and last element are not peak element -> so will apply BS on (1 to n-2) search space
        int s = 1 , e = n-2;
        while(s<=e){
            int mid = s + (e-s)/2;
            // step 3 : sbse pehle check kr ki khi mid hi to peak element nhi hai
            if(v[mid] > v[mid-1] && v[mid] > v[mid+1]) return mid;

            // step 4 : now check if mid is present on left side of peak element -> then will search on right side
            else if(v[mid] > v[mid-1]) s = mid +1;

            // step 5 : now check if mid is present on right side of peak element -> then will search on left side
            else { e = mid - 1;}
            
            
        }
        return -1; // as function have to return something 
            
    }
};