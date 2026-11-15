/* 
Optimized Approch : Explained And Dry Run in Register

NOTE - here we will apply Dijikstra's algo but will use Queue over min-heap priority Queue because , here we are moving level wise and each edge wt is same as 1 , so we don't have to look for smaller edge wt in each level as at a particular level all edge wt will be same

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int ShortestPathBinaryMatrix(vector<vector<int>>&grid , vector<vector<int>>&visited , int n){
        // step 1 : create queue and manually usme {(0,0),1} as {position,distance} daal de
        queue<pair<pair<int,int>,int>>q; //{{row,col},distance}

        q.push({{0,0} , 1}); // intially taken distance as 1  
        visited[0][0] = 1;
        // Now here will do BFS traversal ,till queue does not become empty or we did'nt get (n-1 ,n-1) as (row,col) -> By exploring 8 directions
        
        vector<int>direcRow = {-1, -1, 0 , 1 , 1 , 1, 0 ,- 1};
        vector<int>direcCol = {0 , 1 , 1 , 1 ,0 , - 1, -1 ,-1};

        while(!q.empty()){
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int dis = it.second;
            q.pop();

            // IMP - here also will check ki Destination to khi aa to nhi gya as q.front
            if(row == n-1 && col == n-1) return dis;

            // now explore 8 direction that are possible to be explored and are not visited yet using visited 2d vector
            for(int i = 0 ; i<8 ; i++){
                int nrow = row + direcRow[i];
                int ncol = col + direcCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 0 && visited[nrow][ncol] == 0){
                    q.push({{nrow, ncol},dis + 1});
                    visited[nrow][ncol] = 1;
                }
            }

        }
        return -1;
    }   
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // Edge Case: Start ya End blocked ho
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        // step 1 : hm visited 2d vector bna lenge of grid.size() size
        vector<vector<int>>visited(n , vector<int>(n,0));

        // step 2 : now mrko ek function mai BFS perform karna hai by exploring 8 direction for each 0(unvisited node) and the moment i get grid[n-1][n-1] i will return its distance


        int result = ShortestPathBinaryMatrix(grid , visited , n);
        return result;
    }
};