class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size();
            if(n == 1 && s[0] == '0') return "";

    int indx = -1;
    for(int i = n-1 ; i>=0 ; i--){
        int num = (s[i] - '0')%2;
        if(num != 0 ){
            indx = i;
            break;
        }
    }


    // Agar koi odd digit hi nahi mila (EDGE CASE in case no odd element present in string )
    if(indx == -1) return "";

    int j = 0;
    for(int i = 0 ; i<=indx ; i++){
        if(s[i] != '0'){
            j = i;
            break;
        }
    }

    if(indx!=-1){
        return s.substr(j, indx-j+1);
    }
    else{
        return "";
    }
    }
};