class Solution {
public:

    bool help(string &str , int s ,int e){
        // base case condition
        if(s>=e){
            return true; // means dono pointer cross kr gye -> which means string palindrome tha 
        }
        // agr  non alphanumer incounter hota hai mai start ko 1 position age bda dunga
        if(!isalnum(str[s])){
            return help(str,s+1 ,e);
        }
        // similarly agr non alphanumer incounter hota hai mai end ko 1 position piche bda dunga
        if(!isalnum(str[e])){
            return help(str,s , e-1);
        }

        // agr mujhe kisi bhi point pai start and end pointer wale letter (which must be lowercase ) equal nhi mile i will return false
        if(tolower(str[s])!= tolower(str[e])){
            return false; // means NOT A PALINDROME
        }

        // Recursively function ko call karenge for further moving of pointer to next letter from both end
        return help (str, s + 1, e-1);
    }

    bool isPalindrome(string str) {
    int s = 0;
    int e = str.length() - 1;

    return help(str, s, e);    
    }

    
};