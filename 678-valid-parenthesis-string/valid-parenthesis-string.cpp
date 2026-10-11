class Solution {
public:
    bool checkValidString(string s) {

        int min = 0, max = 0; // representing range

        // step 1 : will iterate string , if '(' will increase min++ , max ++ ,
        // if ')' then min-- , max --  and if '*' then it can do -1 , 0 , +1

        for (auto x : s) {
            if (x == '(') {
                min++;
                max++;
            } else if (x == ')') {
                min--;
                max--;
            } else { // means x = '*'
                min--;
                max++; // its range from [-1 to 1]
            }

            if (min < 0)
                min = 0;
            // if max hi negative hogya , then will return false
            if (max < 0)
                return false;
        }

        return (min == 0);
    }
};