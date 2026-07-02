class Solution {
public:
    
// This function will help in getting the first occurence of target element in sorted vector
int lowerBound(vector<int>&v, int n, int target){
    int ans = n; // by default agr target element nhi mila to ye hypothetical index return krta hai -> which is out of array means n index (Size of array)
    int s = 0 , e = n-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(v[mid] >= target){
            // agr meri lower bound ki condition true hogai -> will look in left side to get the most optimal element which is greater than or equal to target element
            ans = mid;  // ans me maine current lower bound index store kara diya (bcz i hit the lower bound check condition)
            e = mid -1;
        }
        else{
            s = mid +1;
        }
    }
    return ans;
}
 

// This function will help to get the last occurence of target element kyoki upper bound function return index of arr[i]>target , means here arr[i] is -> the smallest element which is greater than target -> so it will return the index of the smallest element greater than target element 
int UpperBound(vector<int>&v, int n, int target){
    int ans = n; // agr target element last element hai sorted array ka so it will return the hypothetical index which -> is the n (which is size of array)
    int s = 0 , e = n-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(v[mid]>target){  
            // means upper bound ki condition hit ho gai -> so i will look in left side to get the index of smallest element which is greater than the target element
            ans = mid;
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
    
} 


    vector<int> searchRange(vector<int>& v, int target) {
        int n = v.size();
        int first = lowerBound(v , n , target);
    // means agr lowerbound n return krta hai means target element present hi nhi hai vector hai + ya jo first index mila vo waha target element hai hi nhi then also first occurence condition fails -> will simply return  {-1,-1}
    if(first == n || v[first] != target ) return {-1,-1}; //is case mai second dhundhne ki jarurat hi nhi will simply return -1,-1


    // agr upr ki if condition fails hoti hai will simply return {lowerbound , upperbound}
    int last = UpperBound(v , n , target);
    return {first  , last -1 };      
    }
};