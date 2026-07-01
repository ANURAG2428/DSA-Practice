class Solution {
public:
    int searchInsert(vector<int>& v, int x) {
        int n = v.size();            
        int s = 0 , e = n-1;
        int ans = n;  // default answer if not found 

        while(s<=e){
            int mid = s + (e-s)/2;

            if(v[mid] >= x){
                ans = mid;  // (POssible Answer )i will simply update Ans which hold lower bound index
                e = mid -1; // will search in left search space to get first lower bound
            }
            else{
                s = mid + 1;  // if mera mid chota nikla x se to mai right side jaunga  
            }

        }
        return ans;
    }
};