class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // Step 1 : trim the string from both starting and ending end via 2 d/f
        // while loops
        int i = 0;
        int j = n - 1; // represents the last character
        while (i <= j && s[i] == ' ')
            i++;
        while (j >= i && s[j] == ' ')
            j--;
        // Step 2 : extract the string which does not have trailing space at the
        // start and end
        s = s.substr(i,
                     j - i + 1); // +1 because -> we have used 0 based indexing

        // Step 3 : ab after extracting above string -> ab mai iska each word ek
        // string vector mai store karaunga
        vector<string> words;
        string word = "";
        // now ab mai simply each word nikalunga aur usko vector mai dalunga
        for (auto c : s) {
            if (c != ' ') {
                word = word + c;
            } else {
                if (!word.empty()) { // this will prevent from storing empty
                                     // string in vector
                    words.push_back(word);
                    word = ""; // word ko dubara empty string kr do
                }
            }
        }

        // Note - last word kabhi vector of string mai jayega nhi bcz last
        // iteration ke baad space hai hi nhi so else kabhi execute nhi hoga so
        // we have to store it in vector manually
        if (!word.empty()) { // word mai last word present hoga so this if will
                             // add that
            words.push_back(word);
        }

        string result = "";

        // Step 4 : ab string vector mai -> mene sare words store kara rakhe hai
        // -> so ab vector ko piche se travese kr aur hr word ke result which is
        // new string usme store kara dunga  hone ke baad space print kr execept
        // 0th index word ko chor ke
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0) {
                result += " ";
            }
        }
        return result;
    }
};