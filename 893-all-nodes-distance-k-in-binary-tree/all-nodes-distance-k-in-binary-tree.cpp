/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Note-  here i will be mapping with recursion
    void MapNodeWithParent(TreeNode* root, TreeNode* parent,
                           unordered_map<TreeNode*, TreeNode*>& mpp) {

        // B.C.C
        if (root == NULL)
            return;

        mpp[root] = parent; // This will help is setting root node's parent as
                            // NULL (jo hi true bhi hai)

        MapNodeWithParent(root->left, root, mpp);
        MapNodeWithParent(root->right, root, mpp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        // step 1 : sabhi node jo bhi tree mai hai unko map krde unke parent se
        unordered_map<TreeNode*, TreeNode*> mpp;

        // step 2 :IMP find kr target node in the tree and usko target mai save

        MapNodeWithParent(root, NULL, mpp);

        // step 3 : ab BFS krte hae target node se store karao vo sare node's ki
        // value jo k distance pai present hai.
        queue<TreeNode*> q1;

        // Here we will create a unordered_map which will store for each node->
        // that the node is visited or not (with the help of bool)
        unordered_map<TreeNode*, bool> mpp2;

        q1.push(target);
        mpp2[target] = true;
        int distance = 0;
        while (!q1.empty()) {
            int size = q1.size();

            if (distance == k)
                break;

            // NOTE - target node se to find konse node at distance k present
            // hai -> to target node se below traversal 3 direction mai ek sath
            // hoga and the moment distanc == k -> will break the while loop
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q1.front();
                q1.pop();

                if (mpp[temp] != NULL && mpp2[mpp[temp]] == false) {
                    q1.push(mpp[temp]);
                    // now mark the pushed node as true
                    mpp2[mpp[temp]] = true;
                }
                if (temp->left != NULL && mpp2[temp->left] == false) {
                    q1.push(temp->left);
                    mpp2[temp->left] = true;
                }
                if (temp->right != NULL && mpp2[temp->right] == false) {
                    q1.push(temp->right);
                    mpp2[temp->right] = true;
                }
            }
            distance++;
        }
        while (!q1.empty()) {
            ans.push_back(q1.front()->val);
            q1.pop();
        }
        return ans;
    }
};