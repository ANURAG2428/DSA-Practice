/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q; // queue is of node* data type
        vector<vector<int>> result;

        // Edge Case :
        if (root == NULL)
            return result;
        q.push(root); // pehle root ko mai manually queue mai daal dunga

        while (!q.empty()) { // jb tk queue empty nhi hoti
            int size =
                q.size(); // hr baar q ke size jitna iteration chalega to store
                          // all node data into a single vector each time
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* temp =
                    q.front(); // is temp node mai hr baar mai queue ke front
                               // means starting mai jo node pda hai usse store
                               // karunga
                q.pop();       // remove the first element from queue

                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
                level.push_back(temp->val);
            }

            result.push_back(level);
        }
        return result;
    }
};