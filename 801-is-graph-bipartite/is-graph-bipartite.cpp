/*

Optimized Approch : Using BFS (Explained In register + with DRYRUN)

*/

#include <bits/stdc++.h>
using namespace std;

// NOTE - the 2 color's are (0/1)

class Solution {

private:
    bool BFSCheckBipartiteGraph(int node, vector<vector<int>>& graph,
                                vector<int>& vis, int V) {
        // step 1 : src node ko pehle vis mai 0 se mark kr do
        vis[node] = 0;

        // step 2 : create a queue of int type which will do BFS traversal
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int newnode = q.front();
            q.pop();

            for (auto adjnode : graph[newnode]) {
                if (vis[adjnode] == -1) { // means not assigned color yet
                    q.push(adjnode);
                    if (vis[newnode] == 0)
                        vis[adjnode] = 1;
                    else
                        vis[adjnode] = 0;
                } else if (vis[adjnode] == vis[newnode])
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) { // here graph is adj(vector)
        int V = graph.size();
        // step 1 : create a vis vector of size V with all node initial value's
        // as -1
        vector<int> vis(V, -1);

        // step 2 : run a for loop , which will help for graph (if its in
        // connected components)
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                /* IMP NOTE -  true return karta hai agar woh component
                 * bipartite ho. Tum pehle hi component ke baad true return kar
                 * doge, baaki components check hi nahi honge. Agar doosre
                 * component mein cycle hui, toh miss ho jaayega. */
                if (!BFSCheckBipartiteGraph(i, graph, vis, V))
                    return false;
            }
        }
        return true;
    }
};