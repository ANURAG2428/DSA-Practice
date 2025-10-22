class Solution {
public:

void Combination(int index, string digits , map<char,string>&mpp , string &ds , vector<string>&store){
    // Base Case Condition
    if(index == digits.size()){
        if(!ds.empty()){
            store.push_back(ds);
        }
        return;
    }

    char digit = digits[index];
    string letters = mpp[digit]; // us particular digit{key} ki {value} dedega 


    for(int i = 0 ; i<letters.size(); i++){
        // Take element
        ds.push_back(letters[i]);
        Combination(index+1,  digits ,mpp,ds,store);
        ds.pop_back(); // Backtrack

    }
}

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        map<char,string>mpp = {
            {'2', "abc"}, 
            {'3', "def"}, 
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string ds = ""; // temporary vector for making subsequnece
        vector<string>store; // for storing the required string 

        Combination( 0 ,digits , mpp ,ds , store);
        return store;
        
    }
};