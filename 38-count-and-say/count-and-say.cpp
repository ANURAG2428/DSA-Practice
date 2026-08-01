class Solution {
public:
    string say(string ans) {
        // step 1: create a result string which will store ans for each i for
        // count and say seq
        string result = "";
        int i = 0;
        int n1 = ans.size();

        while (i < n1) { // jb tk ans string puri iterate nhi ho jati to form
                         // next result string for current i this loop will work

            int cnt =
                1; // either this char is single or the same char is repeater
                   // but cnt hamesha existing char ka 1 to hoga hi

            // for repeated char
            while (i + 1 < n1 && ans[i] == ans[i + 1]) {
                cnt++;
                i++;
            }

            // now ab repeated char wali condition true nhi hai then will
            result = result + to_string(cnt);
            result = result + ans[i];
            i++;
        }
        return result;
    }

    string countAndSay(int n) {
        // Base case , hamesha ans mai 1 to hoga hi to start with que to make
        // nth count and say sequence
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            ans = say(ans);
        }
        return ans;
    }
};