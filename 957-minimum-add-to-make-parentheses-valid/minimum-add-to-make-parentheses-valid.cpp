class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if(n==0) return 0;
        int open = 0 , close = 0;
        for(int i = 0 ; i<n ; i++){
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                if(open > 0){  // means koi opening bracket hai jisko close nhi mila hai 
                    open--;
                }
                else{
                    // if (open == 0) -> means first time close mila hai then mai close ++ kr dunga , bcz this close will depict mrko kitne open chahiye
                    close++; 
                }
            }
        }
        return open + close;
    }
};