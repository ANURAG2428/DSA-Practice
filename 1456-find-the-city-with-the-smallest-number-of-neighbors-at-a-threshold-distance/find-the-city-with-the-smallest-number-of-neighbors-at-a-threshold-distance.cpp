/* 

Optimized Approch : Whole approch written in register with dry run 

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        
        
        // step 1 : is to make matrix , which will store each node distance to all present node
        vector<vector<int>>matrix(n , vector<int>(n,1e9));

        // IMP - matrix mai manually edges ke through jo distance initially input kiye ja skte hai unhe input kra lenge 
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            /* 
            Note - ho skta hai same edge's ke multiple input diyo ho , aur ho skta hai order esa ho ki hmara answer glt aaye so mai min use karunga to assign matrix[u][v] and matrix[v][u] ko shi value se assign krne k liye
            */

            matrix[u][v] = min(matrix[u][v], wt);
            matrix[v][u] = min(matrix[v][u], wt);
        }

        // IMP NOTE - daigonal ko 0 krde , kyoki node ka khud se distance hmesha 0 hi rahgea
        for(int i = 0 ; i<n ; i++){
            matrix[i][i] = 0;
        }
        
        
        // step 2 : apply floyd warshell algo to calculate each node distance with all other node
        for(int k = 0 ; k< n ; k++ ){
            for(int i = 0 ; i<n ; i++){
                for(int j = 0 ; j<n ; j++){
                    if(matrix[i][k] != 1e9 && matrix[k][j] != 1e9 && i!=j){
                        matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        int cntmax = n+1;
        int city = -1;
        // step 3 : iterate over matrix row - wise and store min cnt of a city neighbour in cntmax and cityno in city variable

        for(int i = 0 ;i<n ; i++){
            int cntcity = 0;
            for(int j = 0 ;j<n ; j++){
                if(i!=j && matrix[i][j] <= distanceThreshold) cntcity++;
            }
            if(cntcity<= cntmax){
                cntmax = cntcity;
                city = i;
            }
        }
        return city;
    }
};