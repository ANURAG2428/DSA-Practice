class Solution {
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        if(idx >= l)
            return true;
        
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];  // Step 1 : original character save kro
        board[i][j] = '$';        // Step 2 : Mark Visited   
        

        // Step 3 : All 4 direction try kro
        for(auto& dir : directions) {  // means all 4 direction explore krna us particular char ki position (i,j) se and if kisi bhi dir pai we get element we again call find function for the other character to get the next character of the world.
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(find(board, i_, j_, word, idx+1))
                return true;  // agr mil gya word to true return kro
        }
        

        // Step 4 : Agar koi direction kaam nhi aayi
        board[i][j] = temp;    // Backtrack : Original Character restore kro , kyoki agr current path wrong hoga aur ye step nhi kra to board ke original character change ho jayenge
        return false;          // current path fail hai
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();  // row count (means kitni row hai)
        n = board[0].size(); // ye pehli row ke coloumn count krta hai
        l = word.length();
        if(m*n < l)
            return false;
        
        // Ye function given word ke letter ko find krta hai , aur agr board[i][j] = word[ch] ke equal hote hai tb ye find function chalata hai
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
