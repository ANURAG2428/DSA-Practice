class Solution {
public:

    // Func to get MaxElement
int Func(vector<int>&v , int n){
    int ans = -1;
    for(int i = 0 ; i<n ; i++){
        if(v[i] > ans){
            ans = v[i];
        }

    }
    return ans;
}


long long totalHour(vector<int>&v, int mid , int n){
    long long hrcnt = 0;
    for(int i = 0 ; i<n  ; i++){
        hrcnt = hrcnt + (v[i] + mid -1)/mid;
    }
    return hrcnt;
}


    int minEatingSpeed(vector<int>& v, int h) {
        int n = v.size();
        int maxElement= Func(v,n);
        int k = -1;
        int s = 1 , e = maxElement;
     while(s<=e){
        int mid = s + (e-s)/2;
        long long res = totalHour(v , mid , n);
        if(res<=h){
            k = mid;
            e = mid-1; // will look in left side for smaller k
        }
        else{
            s = mid + 1; // agr res>h -> then i will look in right side to get k which sligtly bigger then current mid
        }
    } 
    return k;

    }
};