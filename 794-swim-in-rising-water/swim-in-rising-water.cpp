
class Solution {
    private:
    int MinTime(vector<vector<int>>&grid , int n , vector<vector<int>>&distance){
        // step 1 : it to create min-heap pq , which will help us to select min-time each time , in order to reach destination
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>>,greater<pair<int , pair<int,int>>>>pq;  // {maxMintime ,row , col }

        // step 2 : manually push src node 
        pq.push({grid[0][0] ,{0,0}});
        // mark this grid[0][0] in distance 2d vector
        distance[0][0] = grid[0][0];

        // step 3 : apply Dijikstra's unitil Pq empty nhi ho jata
        
        while(!pq.empty()){
            auto it = pq.top();
            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            // IMP - optimization -> if curr time is greater than dist[row][col] mai is iteration ko skip kr dunga
            if(time > distance[row][col]) continue;
            
            // Edge case : if row,col = n-1 then simply return time
            if(row == n-1 && col == n-1 ) return time;


            // now explore all 4 direction for pq.top()
            vector<int>drow = {-1,0,1,0};
            vector<int>dcol = {0,1 , 0 ,-1};

            for(int i = 0; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow<n && nrow>=0 && ncol<n && ncol>=0){
                    // upr wala to max time de hi dega
                    int newtime = max(time , grid[nrow][ncol]);
                    
                    // hr baar min time le jitna possible ho skta hai
                    if(newtime < distance[nrow][ncol]){
                        distance[nrow][ncol] = newtime;
                        pq.push({newtime , {nrow , ncol}});
                    }
                }
            }
        }
        return -1;

    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // step 1 : create a 2D - Distance vector whose every node initial max (min time) is 1e9
        vector<vector<int>>distance(n , vector<int>(n , 1e9));
        
        // step 2 : simply apply Dijikstra to get the min time to reach Destination (n-1,n-1)
        int result = MinTime(grid , n , distance);
        return result;
    }
};