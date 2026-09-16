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
    TreeNode *first = NULL, *second = NULL, *prevNode = NULL;
    void visit(TreeNode* curr) {

        // here basically jb jb ye func call ho to first and second node*
        // variable ko agr to inorder traversal mai inconsistancy hai to assign
        // krde

        if (prevNode != NULL &&
            prevNode->val > curr->val) { // as prevNode mera LST mai hoga ,
                                           // means chota hoga curr se (in
                                           // correct inorder traversal of BST)
            if (first == NULL) {
                first = prevNode;
            }
            second = curr; // in only 1 consistancy ya , koi 2 consistancy dono
                           // case mai perfectly fine chalega ye code
        }

        prevNode = curr;
    }

    void recoverTree(TreeNode* root) {
        // Reset global variable for safety
        first = second = prevNode = NULL;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                visit(curr);
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while (temp->right != NULL && temp->right != curr) {
                    temp = temp->right;
                }

                if (temp->right == NULL) {
                    temp->right = curr; // thread banao
                    curr = curr->left;  // to look for further LST to assign
                                        // Leftmost node with their ancestor
                } else {                // temp->right == curr
                    temp->right = NULL;
                    visit(curr);
                    curr = curr->right;
                }
            }
        }

        if (first && second) { // means both pointer are not NULL means are
                               // assigned to some node's of BST whose order is
                               // causing inconsistancy in sorting order
            swap(first->val, second->val);
        }
    }
};