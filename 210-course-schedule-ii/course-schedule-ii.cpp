/* 
- Here will simply perfom Topological sort or DFS to check or detect cycle , if exist , that means all the course's wont get finished so will return false , else will return true .

-Here courses and prerequisite's which are nodes and edges are in DAG(directed asyclic graph) . So we can detect cycle in it

APPROCH Core Idea - will create a result vector to store the ordering of all courses and agr to result.size() == numCourses (means all courses are finished) , else will return empty array
 */
class Solution {
private:
    void BFS(int num , vector<vector<int>>&pre , vector<vector<int>>&adjvector , vector<int>&indegree ,vector<int>&result ){
        // step 0 : create queue
        queue<int>q;

        // step 1 : jo jo nodes ka indegree 0 hai unko queue mai daal
        for(int i = 0 ; i<num ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // step 2 : ab jb tk loop khali nhi hota apply topological sort
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto it : adjvector[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
    }

public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        
        // Here num are the no of nodes and pre is the relation b/w node's
        // step1 : make new adjlist and indegree vector
        vector<vector<int>>adjvector(num);
        vector<int>indegree(num , 0);
        for(auto it : pre){
            int a = it[0]; // courses jo baad mai krna hai
            int b = it[1]; // course jo pehle krna hai

            adjvector[b].push_back(a);  // since relation (b->a) hai so , indegree a ki ++ hogi
            indegree[a]++;
        }

        // Core concept : now call topological sort (if cnt of no course in queue === num ) -> it means all courses can be finished , and there is no cycle , else cycle exists
        vector<int>result;
        BFS(num , pre , adjvector , indegree , result );
        // IMP STEP - now check kr agr to result.size() == numCourses will return result vector , else will return empty vector
        if(result.size() == num) return result;
        else return {};
    }
};