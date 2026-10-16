/* 

Optimized Approch : here will not use adjvector , will cnt province's direcly from matrix

*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void DFS(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[node] = 1;

        for(int j = 0 ; j<isConnected.size() ; j++) {
            if(isConnected[node][j] == 1 && vis[j] == 0) {
                DFS(j, vis, isConnected);
            }
        }
    }

    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();


        vector<int> vis(v, 0);
        int cnt = 0;

        for(int i = 0; i < v; i++) {
            if(vis[i] == 0) {
                cnt++;
                DFS(i, vis, isConnected);
            }
        }

        return cnt;
    }
};
