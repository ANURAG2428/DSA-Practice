/*

Optimized Approch : So to find the safe node's mai "given directed graph mai
cycle detect karunga using vis and pathvis vector , agr to cycle detect hui so
vo sare nodes and us se connected node's can never be safe node . Agr cycle
detect nhi hui -> that node's will be pushed in safe node vector . "

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool DFS(int node, vector<int>& vis, vector<int>& pathvis,
             vector<vector<int>>& graph, vector<int>& result,
             vector<int>& safe) {
        // step 1 : mark ith node as vis in visted vector and pathvis vector
        vis[node] = 1;
        pathvis[node] = 1;

        // step 2 : now ab adjnode iterate kr and agr unvisited hai to unke liye
        // DFS call kr
        for (auto adjnode : graph[node]) {
            if (vis[adjnode] == 0) {
                if (!DFS(adjnode, vis, pathvis, graph, result, safe)) {
                    safe[node] = 0;    // unsafe
                    pathvis[node] = 0; // backtrack
                    return false;
                }

            } else if (pathvis[adjnode] ==
                       1) {        // means there exist cycle in graph
                safe[node] = 0;    // unsafe
                pathvis[node] = 0; // backtrack
                return false;
            } else if (safe[adjnode] == 0) {
                safe[node] = 0;
                pathvis[node] = 0;
                return false;
            }
        }
        // step 3 : Saare neighbour explore ho gye , koi cycle nhi mili -> safe
        // node
        pathvis[node] = 0; // backtrack (remove from current path)
        safe[node] = 1;    // mark as safe
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        // step 1 : make vis and pathvis vector of size graph.size() which is V
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);

        vector<int> safe(
            V, 0); // store all node which are safe , by puting 1 at their index
        vector<int>
            result; // this will store all the safe node in ascending order
        // step 2 : iterate vis vector for each node DFS check (weather cycle
        // exist or not)
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                DFS(i, vis, pathvis, graph, result, safe);
            }
        }

        // step 3 : safe node ko result vector mai dalo
        for (int i = 0; i < V; i++) {
            if (safe[i] == 1) {
                result.push_back(i);
            }
        }
        return result;
    }
};