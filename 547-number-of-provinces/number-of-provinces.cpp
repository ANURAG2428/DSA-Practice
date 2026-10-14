class Solution {
private:
    void BFS(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1 && vis[j] == 0) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                BFS(i, isConnected, vis);
            }
        }
        return cnt;
    }
};