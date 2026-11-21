class Solution {
    private:
    int NetworkMaxTime(vector<vector<int>>&times ,int n ,int k , vector<vector<pair<int,int>>>&adjvector , vector<int>&distance){
        // step 1 : create min-heap priority queue {distance, node}
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;

        // step 2 : manually push k node with distance 0 in pq
        pq.push({0,k});

        // step 3 : jb tk pq empty nhi ho jati apply shortest path
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();

            // Stale entry
            if(dis > distance[node]) continue; 

            for(auto it1 : adjvector[node]){
                int neighnode = it1.first;
                int time = it1.second;

                if(distance[neighnode] > dis + time){
                    distance[neighnode] = dis + time;
                    pq.push({distance[neighnode] , neighnode});
                }
            }

        }

        // step 4 : now iterate over distance vector at any moment you encounter "1e9" simply return -1 else return max in distance
        int maxtime = INT_MIN;
        for(int i = 1 ; i<=n ; i++){
            if(distance[i] == 1e9) return -1;
            maxtime = max(maxtime , distance[i]);
        }
        return maxtime;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // step 1 : create adjvector that will store directed graph node's neighbour -> which will be used in Dijikstra's algo
        // since indices in 0 se shuru hoti hai that's why (n+1)
        vector<vector<pair<int,int>>>adjvector(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjvector[u].push_back({v,wt});
        }   

        // step 2 : create distance vector of size n with intial all node values 1e9
        vector<int>distance(n+1, 1e9);
        distance[k] = 0;

        // step 3 : call Dijikstra's
        int result = NetworkMaxTime(times , n , k , adjvector , distance);
        return result;
    }
};