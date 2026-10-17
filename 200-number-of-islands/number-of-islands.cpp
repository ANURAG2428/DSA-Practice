/* 

Optimized Approch : Explained In register

*/


#include<bits/stdc++.h>
using namespace std;


class Solution{

    private:
    void BFS(int row , int col , vector<vector<int>>&vis , vector<vector<char>>&grid){
        // step 1 : is to mark the current (row,col) element with 1
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();  

        // step 2 : create a queue of pair type 
        queue<pair<int,int>>q;
        q.push({row,col});

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        // step 3: now jb tk queue , empty nhi hota perform BFS traversal
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            // step 4 : pop the front element
            q.pop();
            
            // step 5 : now ab hr node 4 direction mai traverse kar , jaha jaha 1 hai unko visited vector mai 1 kr de , taaki it will ease the traversal (VV IMP)
            for(int d = 0 ; d<4 ; d++){
                int nrow = row + dr[d];
                int ncol = col + dc[d];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol <m
                && grid[nrow][ncol] == '1' && vis[nrow][ncol] ==0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
                
            }
            
        }
    }

    public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();  // no of coloumn
        
        // create a visited 2D - vector , which will help to know which node index is visited and which not
        vector<vector<int>>vis(n , vector<int>(m,0));

        // now iterate through each matrix element , and count the no of islands using BFS traversal
        int cnt = 0 ;
        for(int row = 0 ; row<n ; row++){
            for(int col = 0 ; col<m ; col++){
                if(vis[row][col] == 0 && grid[row][col] == '1'){
                    cnt++;
                    BFS(row , col , vis , grid);
                } 
            }
        }
        return cnt;
    }
};