/* 

Optimized Approch : Written in Register with Dry Run

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int minEffor(vector<vector<int>>&heights ,int n , vector<vector<int>>&distance){

        // Same here also will manually get row and col of height
        int r = heights.size();
        int c = heights[0].size();

        // step 1 : is to create min-heap priority_qeueu that will store (effort , row ,col) way
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        // step 2 : manually push (0,0,0) in pq as effort 0 at (0,0) row , col
        pq.push({0, {0,0}});

        // step 3 : now jb tk pq empty nhi ho jata will explore path based upon Dijikstra's algo and using min-heap pq each time i will get min effort path with the help of pq.top()

        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // now pop the pq.top()
            pq.pop();   

            // IMP NOTE - agr mera current pq.top() destination hi hai to mai sidha effort return kra dunga , (Bcz using dijikstra's will eventually lead me to min effort using min-heap pq)
            if(row == r-1 && col == c-1) return effort; 

            // Edge Case : for optimizing code
            if(effort > distance[row][col]) continue;

            // IMP - now for current pq.top explore all valid 4 direction if possible
            for(int i = 0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // now check kr boundary then pq mai push kr new ({effor,{row,col}}) to get min effort
                if(nrow>=0 && nrow<r && ncol>=0 && ncol<c ){
                    // now check new effort (kyoki (n-1,n-1) , pai pahuchte hue mujhe sbse min effort chahiye )
                    int neweffort = max(effort , abs(heights[row][col] - heights[nrow][ncol] ));

                    if(neweffort < distance[nrow][ncol]){
                        // since we need min-effort so will assign distance[nrow][ncol] with neweffort and will push them in pq
                        distance[nrow][ncol] = neweffort;
                        pq.push({neweffort, {nrow , ncol}});
                        
                        
                    }
                }

            }
        }
        return 0;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // VV IMP - here it is no where written that height is square matrix , so will check its Row and col and then work according to them
        int r = heights.size();
        int c = heights[0].size();
        
        int n = heights.size();
        // step 1 : is to create distance vector with (0,0) cell as 0 , else all assigned to inifinity (1e9)
        // for memoization
        vector<vector<int>>distance(r , vector<int>(c , 1e9));
        distance[0][0] = 0;
        
        
        // Function that will return min effort req to travel from top-left to bottom-right
        int result = minEffor(heights , n , distance);
        return result;
    }
};