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
    vector<int> rightSideView(TreeNode* root) {
        

        // step 0 : create vector that will store right side view
        vector<int> ans;

        // Edge Case :
        if(root == NULL){
            return ans;
        }

        // step 1 : create a queue which will store node in it
        queue<TreeNode*> q;
        // step 2 : manually push kr root in node
        q.push(root);
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                // means we are at the right most node of the tree right now
                if (i == size - 1) {
                    ans.push_back(temp->val);
                }
                // simply push temp's left and right root into queue
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};