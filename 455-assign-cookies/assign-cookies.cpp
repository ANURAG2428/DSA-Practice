class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // step 1 : sort g and s in increasing order via built in sort()
        sort(g.begin() , g.end());  // greed vector for childer
        sort(s.begin() , s.end());  // cookie vector 

        // now using two seprate pointer starting from 0th index for both vector iterate both sorted array
        int cnt = 0; // represents max no of content children
        int i = 0, j = 0;

        while( i < g.size() &&  j < s.size()){
            if(s[j] >= g[i]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};