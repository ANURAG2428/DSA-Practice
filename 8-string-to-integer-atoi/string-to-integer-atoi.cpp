/* 
⏱ Time Complexity : 
While loop (whitespace + sign skip)
Ye at most O(N) time lega (poora string traverse ho sakta hai worst case me).
Recursive calls (digit process)
Agar string me k digits hain, to k recursive calls lagenge. Ye bhi O(k) ≤ O(N) hai.
✅ Total time = O(N) + O(N) = O(N)
(Big-O notation me constant factor 2 ignore ho jata hai).



\U0001f4be Space Complexity :
Har recursive call stack me pending hoti hai jab tak uska base case nahi aata.
Agar k digits hain, to recursion depth k hogi.
Worst case: O(N) extra stack space lagega.
✅ Space = O(N)


NOTE - it is not an optimal approch , ye to bus recursion ka smjhneke liye likha gya hai


isdigit() - ye built in function check krta hai current letter digit hai ya nhi 
 */



/* 
"PARAMETERIZED RECURSION -> take place hua hai idhr"

T.C = o(n)[while loop] + o(n) [n function call] = o(2n) = o(n)
S.C = o(n)
 */

class Solution {
public:
    int solve(string &str, int i, long num, int sign) {
        // ✅ CORRECTED BASE CASE
        if(i >= str.size() || !isdigit(str[i])) { // jese hi ye dono mai se koi bhi condition true hui -> jo bhi num abhi tk string se int mai convert hua hai mai return kara dunga
            return (int)(sign * num);
        }

        // Digit convert kro
        int digit = str[i] - '0';  // digit jo ki string mai hai unhe  int mai convert karane ke liye ASCII value ka use kara hai 
        num = num * 10 + digit;

        // Overflow check
        // Rounded wali condition -> jese hi meri string jb num mai convert hoti hai aur vo num greater than 2^31 - 1 or less than 2^-31 ko exceed kr jata hai return INT_MAX and INT_MIN 
        if(sign == 1 && num > INT_MAX) {
            return INT_MAX;
        }
        if(sign == -1 && -num < INT_MIN) {
            return INT_MIN;
        }

        // Recursive call
        return solve(str, i + 1, num, sign);
    }

    int myAtoi(string str) { // yaha se code execute hona shuru hoga
        int i = 0;
        
        // Whitespaces skip
        while(i < str.size() && str[i] == ' ') i++; 
        // agr pehla letter hi whitesspace hai to -> whitespace encounter hone pai hm i iterator ko aage move karate jayenge , until hm digit encounter nhi krte (traversal krte hue)

        // Handle sign
        int sign = 1;
        if(i < str.size() && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i] == '-') ? -1 : 1;
            // ternary operator says -> agr str[i] =='-' is true then sign = -1 ho jayega , vrna kisi bhi aur case mai sign = 1 rahega 
            i++;  // iterator ko aage move kara diya
        }

        // ✅ ADD: Non-digit milte hi return 0
        if(i < str.size() && !isdigit(str[i])) { 
            // agr shuruwat mai hi ya traverse krte isi function mai hi agr mera iterator size of string se choti position pai hai aur current index pai mujhe non-digit encounter ho jati hai to acc to question -> i will return 0;
            return 0;
        }
        // NOTE -> "Agar shuruwat mein hi non-digit mil gaya, toh recursive function execute karane ki jarurat hi nahi hai - directly return 0 kar do!"



        return solve(str, i, 0, sign); // recursive function call krdiya -> yaha upar ke sare operation se question mai diye hue edge cases ko handle kr liya hoga -> ab recursion karana easy rahega 
    }
};