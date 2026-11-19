/* 
Optimized Approch : Written and Explained in register
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {

    private:
    void BFS(int n , vector<vector<int>>&flights, int src, int dst ,int k , vector<vector<pair<int,int>>>&adjvector , vector<int>&distance ){
        // step 1 : is to create queue of type {stop , node , distance}
        queue<pair<int,pair<int,int>>>q;

        // step 2 : manually src node push kr with stop as 0 and distance as 0
        q.push({0 , {src , 0}});

        // step 3 : Perfrom bfs traversal till queue empty nhi ho jata 
        while(!q.empty()){
            auto it = q.front();
            int stop = it.first;
            int node = it.second.first;
            int dist = it.second.second;
            // remove this front element from queue , as we are exploring its neighbour 
            q.pop();

             /* If the number of stops taken exceed k,
            skip and move to the next element */
            if(stop > k) continue;

            for(auto it1 : adjvector[node]){
                int neighnode = it1.first;
                int cost = it1.second;

                if(dist + cost < distance[neighnode] && stop<= k){
                    cost = dist + cost;
                    distance[neighnode] = cost; // distance vector ko bhi to update karenege
                    q.push({stop+1 , {neighnode , cost}});
                }
            }
        }

    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // step 1 : create a 2d adjvector which will store all nodes neighbour and their cost to reach there
        vector<vector<pair<int,int>>>adjvector(n);

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adjvector[u].push_back({v,cost});
        }

        // step 2 : is to create a distance vector of size n (created for distance memoization) , with all value's initially as 1e9 , except src which is 0
        vector<int>distance(n, 1e9);
        distance[src] = 0;

        // Call BFS so that via distance vector we can get the cheapest flights within K stops
        BFS(n , flights, src, dst , k , adjvector , distance );
        if(distance[dst] == 1e9) return -1;
        return distance[dst];
        
    }
};