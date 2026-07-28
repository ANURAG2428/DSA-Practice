class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        // Step 1 : set 2 variable which will help
        int sign = 1; 
        long long num = 0;
        int i = 0;

        // step 2 : Leading space skip kro clean tarike se
        while (i < n && s[i] == ' ')
            i++;

        // step 2 : sign handle kro
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        // step 3: digits parse kro (0 skip mt karo , automaticall adjust ho
        // jayega trailing aur betwenn 0)
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                int currnum = s[i] - '0';
                num = num * 10 + currnum;
                if (num * sign > INT_MAX)
                    return INT_MAX;
                if (num * sign < INT_MIN)
                    return INT_MIN;
                i++;
            } else {
                // non digit pe ruk jao
                break;
            }
        }
        return num * sign;
    }
};