/*

Optimized Approch : Explained in Register

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // step 1 : get no of rows and col
        int n = mat.size();
        int m = mat[0].size();

        // step 2 : create distance and vis 2d vector Matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));

        // IMP = Queue for BFS traversal
        queue<pair<pair<int, int>, int>> q; // q(row , col ,distance)

        // step 3 : initally jitne bhi 0 hai unka distance dis matrix mai daal
        // de and unko vis mai 1 krde
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                }
            }
        }

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        // step 4 : ab queue ko tb tk chala jb tk empty nhi ho jata and dis mai
        // hr node pai present value ke base pai nearest 0 se distance daal ,
        // using visited 2d vector matrix
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            // now explore in 4 direction for each node
            for (int k = 0; k < 4; k++) {
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0) {
                    dis[nrow][ncol] = dis[r][c] + 1;
                    q.push({{nrow, ncol}, d + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return dis;
    }
};