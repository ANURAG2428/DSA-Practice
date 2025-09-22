class Solution {
public:
    int solve(string &str, int i, long num, int sign) {
        // ✅ CORRECTED BASE CASE
        if(i >= str.size() || !isdigit(str[i])) {
            return (int)(sign * num);
        }

        // Digit convert kro
        int digit = str[i] - '0';
        num = num * 10 + digit;

        // Overflow check
        if(sign == 1 && num > INT_MAX) {
            return INT_MAX;
        }
        if(sign == -1 && -num < INT_MIN) {
            return INT_MIN;
        }

        // Recursive call
        return solve(str, i + 1, num, sign);
    }

    int myAtoi(string str) {
        int i = 0;
        
        // Whitespaces skip
        while(i < str.size() && str[i] == ' ') i++;

        // Handle sign
        int sign = 1;
        if(i < str.size() && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        // ✅ ADD: Non-digit milte hi return 0
        if(i < str.size() && !isdigit(str[i])) {
            return 0;
        }

        return solve(str, i, 0, sign);
    }
};