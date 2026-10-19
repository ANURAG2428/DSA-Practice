/*

Optimized Approch : Written in register

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // step 1 : no of row and col nikal le grid ki sbse pehle
        int n = grid.size();
        int m = grid[0].size();

        // step 2 : create a visited 2d vector which help , in queue , to check
        // ki koi 1 jo hai vo already visited to nhi hai vo 0 hi hai na
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 3 : Create queue of pair of pair int type (row ,col ,time)
        queue<pair<pair<int, int>, int>> q;

        // IMP - create countfresh , tmax variable
        int cntfresh = 0;
        int tmax = 0;

        // step 4 : sbse pehle vis mai 2 mark kr de and all inital 2(rotten
        // orange's ) at time = 0 ko ek sath queue mai daal de as 1st level , jo
        // ki ek sath explore honge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    cntfresh++;
                }
            }
        }

        // step 5 : now ab explore all the current time rotten orange's present
        // at each level , together and make all the neighbouring fresh orange's
        // rotten

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        int newlyrottent = 0; // count of newly fresh orange's that get rotten
                              // due , to being neighbour of rotten orange's

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // update tmax
            tmax = max(t, tmax);

            // now for this q.front() explore its 4 direction's
            for (int d = 0; d < 4; d++) {
                int nrow = r + drow[d];
                int ncol = c + dcol[d];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    newlyrottent++;
                }
            }
        }

        // step 6 : now check kr agr to cntfresh == newlyrotten (means sare
        // fresh orange's rotten hogye hai succesfully , then will return tmax)
        // , else will return -1
        if (cntfresh == newlyrottent)
            return tmax;
        else
            return -1;
    }
};