class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x); 
        int n = str.size(); // size of the string
    
        // 2 POINTER APPROCH : here we will be using two pointer approch by taking two pointer s and e at the extreme end and we will start comparing them by moving them toward each other , if the pointer data matche's then its a palindrom otherwise it's not a palindrome
        int s = 0 , e = n -1;
        while(s<e){
            if(str[s]!=str[e]){
                return false;
            }
            else{
                s++;
                e--;
            }
        
        }
        return true;
        
    }
};