/* 

Optimized Approch : Explained And Dry run in Register

- Here it is undirected Graph
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int NoofWays(vector<vector<int>>&roads , vector<vector<pair<int,int>>>&adjvector ,int n , vector<long long>&distance , vector<int>&ways){
        // step 1 : create min-heap priority_queue {MinTime , Node}
        priority_queue<pair<long long,int> , vector<pair<long long,int>>, greater<pair<long long,int>>>pq;

        // step 2 : manually push roads[0] and 0 as min time
        // NOTE -Start node hamesha 0 hota hai, aur uska time 0 hota hai. roads[0][0] ka matlab hai pehli road ka starting node, jo zaroori nahi ki 0 ho.
        pq.push({0 , 0});

        // step 3 : now run while loop till Pq -> does not get empty
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long mintime = it.first;
            int node = it.second;

             // Stale entry skip (Optimization)
            if(mintime > distance[node]) continue;

            for(auto it1 : adjvector[node]){
                int neighnode = it1.first;
                int neighbtime = it1.second;

                long long newTime = distance[node] + neighbtime;

                // Impnote - agr mera newtime purane wale time se chota hai then mai newtime se distance[neighnode] ko update kra dunga and ways[neighnode] = ways[node]
                if( newTime < distance[neighnode] ){
                    distance[neighnode] = newTime;
                    ways[neighnode] = ways[node]; // Reset ways
                    pq.push({newTime , neighnode});
                }
                
                else if(newTime == distance[neighnode]){ // means equal hai , already present , pq so in this case no of ways[neighnode] mai ways[node] add kr dunga for correct answer
                    // As asked to do in the question
                    ways[neighnode] = (ways[neighnode] + ways[node]) % 1000000007; // Add ways
                    
                } 
                // Else wala case agr mera newTime bda hai distance[neighnode] => so koi fayda hi nhi hai to work on this , so mai simply is case ko skip kr dunga
            }
        }
        return ways[n-1]; // last node which is destination node

    }   
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // step 1 : is to make adjvector to store each node neighbour with their respective time(distance)
        vector<vector<pair<int,int>>>adjvector(n);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adjvector[u].push_back({v,t});
            adjvector[v].push_back({u,t});
        }

        /* step 2 : create 2 vectors 
        1) distance vector which will store min time to reach each node
        2) ways vector which will store no of ways to reach each node
        */
       vector<long long>distance(n , 1e18);
       distance[0] = 0;
       vector<int>ways(n,0);
       ways[0] = 1;

        //    Here we are applying Dijikstra's algo
        int result = NoofWays(roads , adjvector , n , distance , ways);
        return result;

    }
};