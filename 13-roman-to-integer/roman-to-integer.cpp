class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
            // step 0 : create an unordered_map where we will store key:value
    unordered_map<char ,int >mpp = {
        {'I',1} ,
        {'V',5} ,
        {'X',10} ,
        {'L',50},
        {'C',100},
        {'D',500} ,
        {'M',1000}
    };



    int sum =0 ; // intialize sum = 0
    // step 1 : linearly iterate kr string
    for(int i = 0 ; i<n ; i++){
        if(s[i] == 'I' && i<n-1 && (s[i+1] == 'V' || s[i+1] == 'X')){
            sum = sum - 1;
        }
        else if(s[i] == 'X' && i<n-1 && (s[i+1] == 'L' || s[i+1] == 'C')){
            sum = sum - 10;
        }
        else if(s[i] == 'C' && i<n-1 && (s[i+1] == 'D' || s[i+1] == 'M')){
            sum = sum - 100;
        }
        else{
            sum = sum + mpp[s[i]];
        }
    }
    return sum ;
        
    }
};