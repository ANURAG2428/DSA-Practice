class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // Step 1 : input string ko reverse kro
        reverse(s.begin(), s.end());
        // step 2 : create an ans string which will have final reversed word
        // string
        string ans = "";

        // Step 3 : simply ab reversed string pai iterate kr + is for loop se "
        // " spaces automatically ignore ho jayenge and each word -> each time
        // would get stored in string word and will reverse that and store in
        // ans
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word = word + s[i];
                i++;
            }

            // now ab jo word mila hai usse reverse kr de
            reverse(word.begin(), word.end());
            if (word != "") {
                ans = ans + " " + word;
            }
        }
        return ans.substr(
            1); // means 1st index se puri string a subsstring return krdo
    }
};