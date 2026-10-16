class Solution {
    private:
    void DFS(int node , vector<int>&vis , vector<vector<int>>&adjv){
        // step 1 : sbse pehle curr node ko vis vector mai 1 mark kr
        vis[node] = 1;

        // now ab adj-vector mai jo iske neighbour store kre hai , unhe traverse kr using loop , recursively whole adj list will get traversed
        for(auto &it : adjv[node]){
            // step 2 : ab it mai present node ko check kr ki agr to ye vis[it] == 0 , hai then to isko traverse kr further traversal , else mt kr traverse
            if(vis[it] == 0){
                // now ab is "it" ke liye DFS call kr 
                DFS(it , vis , adjv );
            }
        }
    }

    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size(); // this will represent no of nodes
        // step 1 : create adjvector from above matrix given
        vector<vector<int>>adjv(v);

        for(int i = 0 ; i<v ; i++){
            for(int j = 0 ; j<v ; j++){
                // now store each node -> neighbours in adjvector . IMP COND : (i!=j)
                if(isConnected[i][j] == 1 && i!=j){
                    adjv[i].push_back(j);
                    adjv[j].push_back(i);
                }
            }
        }

        // step 2 : create a visited vector which will help in traversing nodes' which are not connected via edge directly
        vector<int>vis(v,0);
        int cnt = 0; // this will help in counting no of province's
        for(int i = 0 ; i<v ; i++){
            if(vis[i] == 0){
                cnt++; // as new province will start every time , this loop execute for i , so i can store the new province count in 'cnt'
                // step 3 : call DFS traversal for that node
                DFS(i , vis , adjv);
            }
        }
        return cnt;

    }
};