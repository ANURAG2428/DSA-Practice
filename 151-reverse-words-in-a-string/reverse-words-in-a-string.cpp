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
        for (int i = 0; i < n;i++) { //  IMP - as it is nested loop iska ye mtlb nhi ki iski T.c
                    //  = O(N^2) hogi -> kyoki yaha andar hm same i ke sath kaam
                    //  kr rhe hai while loop mai -> we are iterating it
                    //  linearly respective to both loop
            string word = "";
            while (i < n && s[i] != ' ') {
                word = word + s[i];
                i++;
            }

            // now ab jo word mila hai usse reverse kr de
            reverse(word.begin(), word.end());
            // Isko replace kar do
            if (!word.empty()) {
                if (!ans.empty())
                    ans += ' '; // Pehle space daalo agar ans khaali nahi hai
                ans += word;    // Sirf word append karo (O(1) amortized)
            }
        }
        return ans; // means 1st index se puri string a subsstring return krdo
    }

};