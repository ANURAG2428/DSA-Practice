
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string current = "";
        backtrack(0, 0, 0, num, target, current, result);
        return result;
    }
    
private:
    void backtrack(int index, long prev, long currentValue, string& num, int target, string& current, vector<string>& result) {
        // Base case: saare digits process ho gaye
        if (index == num.size()) {
            if (currentValue == target) {
                result.push_back(current);
            }
            return;
        }
        
        // Try different length ke numbers banaye
        for (int i = index; i < num.size(); i++) {
            // Leading zero check - "05" jaise cases avoid karo
            if (i > index && num[index] == '0') {
                break;
            }
            
            // Current number nikaalo
            string numStr = num.substr(index, i - index + 1);
            long numVal = stol(numStr);
            
            // Agar pehla number hai
            if (index == 0) {
                current += numStr;
                backtrack(i + 1, numVal, numVal, num, target, current, result);
                current.erase(current.size() - numStr.size());
            } 
            // Operators ke saath try karo
            else {
                // Addition try karo
                current += "+" + numStr;
                backtrack(i + 1, numVal, currentValue + numVal, num, target, current, result);
                current.erase(current.size() - numStr.size() - 1);
                
                // Subtraction try karo
                current += "-" + numStr;
                backtrack(i + 1, -numVal, currentValue - numVal, num, target, current, result);
                current.erase(current.size() - numStr.size() - 1);
                
                // Multiplication try karo - special handling
                current += "*" + numStr;
                backtrack(i + 1, prev * numVal, currentValue - prev + prev * numVal, num, target, current, result);
                current.erase(current.size() - numStr.size() - 1);
            }
        }
    }
};