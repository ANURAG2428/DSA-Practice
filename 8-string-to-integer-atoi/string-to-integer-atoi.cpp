class Solution {
public:
    int myAtoi(string s) {
         int i = 0, n = s.length();
        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional '+' or '-' sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to number
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Clamp result if it goes out of int range
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;

            i++;
        }

        return result * sign;
    }
};