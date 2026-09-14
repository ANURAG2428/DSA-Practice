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
    bool isValidBST(TreeNode* root) {
        TreeNode* prevNode = NULL;
        bool isValid = true;

        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                // Visit node
                if (prevNode != NULL && prevNode->val >= curr->val) {
                    isValid = false;
                }
                prevNode = curr;
                curr = curr->right;
            } else {
                // Predecessor dhoondho (left subtree ka rightmost)
                TreeNode* store = curr->left;
                while (store->right != NULL && store->right != curr) {
                    store = store->right;
                }

                if (store->right == NULL) {
                    // Thread banao
                    store->right = curr;
                    curr = curr->left;
                } else {
                    // Thread hatao, node visit karo
                    store->right = NULL;
                    if (prevNode != NULL && prevNode->val >= curr->val) {
                        isValid = false;
                    }
                    prevNode = curr;
                    curr = curr->right;
                }
            }
        }
        return isValid;
    }
};