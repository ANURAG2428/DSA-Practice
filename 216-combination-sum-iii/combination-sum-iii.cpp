class Solution {
public:

void findCombination(int start, int k, int target, vector<int>& current, vector<vector<int>>& result) {
    // Base cases
    if(k == 0 && target == 0) {
        result.push_back(current);
        return;
    }
    if(k == 0 || target < 0) return;
    
    // 1 se 9 tak try karo
    for(int i = start; i <= 9; i++) {
        current.push_back(i);
        findCombination(i + 1, k - 1, target - i, current, result);
        current.pop_back(); // Backtrack
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current; //temporary vector used for making subsequence acc to condition
        vector<vector<int>>result; // isme hm combination store karayenge
        findCombination(1,k,n,current,result);
        return result;
        
    }
};