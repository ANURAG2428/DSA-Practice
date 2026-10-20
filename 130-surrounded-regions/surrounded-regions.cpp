/*

Most Optimized Approch : here i will do in-place manipulation so S.C = O(1)

NOTE - As asked in question to do in-place manipulation
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    void DFS(vector<vector<char>>& board, int row, int col, vector<int>& delrow,
             vector<int>& delcol, int n, int m) {
        // step 1 : mark them in vis 2d vector
        board[row][col] = '#';

        // step 2 : explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O') {
                DFS(board, nrow, ncol, delrow, delcol, n, m);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        // step 1 : get the no of rows and col of the board
        int n = board.size();
        int m = board[0].size();

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        // step 3 : IMP - here instead of scanning whole 2D matrix which will
        // take (n*m) T.c mai idhr alg se sirf 4 boundry scan karunga
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                DFS(board, 0, j, delrow, delcol, n, m);
            if (board[n - 1][j] == 'O')
                DFS(board, n - 1, j, delrow, delcol, n, m);
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                DFS(board, i, 0, delrow, delcol, n, m);
            if (board[i][m - 1] == 'O')
                DFS(board, i, m - 1, delrow, delcol, n, m);
        }

        // step 4 : now ab jin jin ka visited 1 hai unko to 'O' rehne diyo ,
        // jinka nhi hai unka X kr diyo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] ==
                    '#') { // Means board mai jo 'O' hai vo non visited hai ,
                           // means beech mai hai not touching the boundary unhe
                           // 'X' krdo
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};