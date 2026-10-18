/* 

Optimized Approch : Explained in Register

*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();  // no of rows
        int m = grid[0].size(); // no of col

        // step 1 : create a visited vector with all value 0 (initially)
        vector<vector<int>>vis(n, vector<int>(m,0));

        // step 2 : now will iterate over boundry of the grid matrix and will put 1 in all those indexes in vis[][] where grid have 1 , But here we are using BFS , so will be using queue , which contains the postion of boundry "1" . Which on each time will help boundry 1 neighbours to be 1 on the visited 2d vector
        queue<pair<int,int>>q;

        for(int i = 0 ;i<n ; i++){
            for(int j = 0 ; j<m ; j++ ){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        /* imp DelRow and DelCol needed to explore 4 direction for  each 1 index for below step */
        vector<int>delrow = {-1, 0 , 1 ,0};
        vector<int>delcol = {0 , 1 , 0 ,-1};

        // step 3 : now ab mai queue ki help se q.first krke using while loop hr 1 ke neighbour explore karunga and agr grid mai un neighbour ki place mai 1 hai then mai udhr bhi 1 kr dunga in visited 2d vetor
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // now for each node explore 4 neighbour
            for(int d = 0 ; d<4 ; d++){
                int nrow = r + delrow[d];
                int ncol = c + delcol[d];

                if(nrow>= 0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol] ==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }


        // step 4 : now iterate over grid matrix and which ever index has 1 and his vis[indx] == 0 , increase the cnt and at the end return the cnt
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};