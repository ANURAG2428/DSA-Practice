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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* curr = root;
        while (curr !=
               NULL) { // Since ye NULL hoga nhi kabhi , as given in the
                       // constraint that both p and q are present in BST

            // move left
            if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            }
            // move right
            else if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            }
            // split point or dono mai se koi ek mil gya then
            else {
                return curr;
            }
        }
        return NULL;
    }
};