class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        // EDGE CASE 1 : if size of vector is 1 simply return v[0]
        if(n==1) return v[0];

        int s = 0 , e = n-1;
        // Step 1: Check agr to first most aur last most element mai se hi koi single element to nhi hai agr hai to simply return that
        if(v[s] != v[s+1]) return v[s];
        else if(v[e] != v[e-1]) return v[e];
        else{ s++ , e--;}
        // step 2 : calculate mid
        while(s<e){  // here equal to (s<=e) nhi ayega -> kyoki ye condition pai kbhi single element mil hi nhi skta 
            int mid = s + (e-s)/2;
            // step 3 : check kr ki ye even index pai ya odd pai , agr even pai hai to usi index pai rehn de else if mid index is odd -> mid = mid-1
            if(mid%2 != 0) mid--; 
        
            // step 4 : simply check kr ki mid wala element left aur right dono element mai se jis side bhi match kha rha hai us side pai search space ko navigate kr de else return v[mid]
            if(v[mid] == v[mid-1] && v[mid]!= v[mid+1]) e = mid -1;
            else if( v[mid]!= v[mid-1] && v[mid] == v[mid+1]) s = mid + 1;
            else{return v[mid];}
        }

        return -1;

    }
};