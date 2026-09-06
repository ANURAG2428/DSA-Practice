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
    void flatten(TreeNode* root) {
        // step 1 : mene curr as temp node liya to do operation -> to not lost
        // root node
        TreeNode* curr = root;

        // step 2 : jb tk curr == Null naa ho jaye means sare nodes Morris
        // Preorder traversal se configure na ho jaye -> tb tk inner
        // functionality perform karate rho
        while (curr != NULL) {

            // step 3 : curr->left -> should not be null -> agr hai to right
            // pointer pai move kr jao curr = curr ->right
            if (curr->left != NULL) {
                // step 4 : agr left null nhi hai to prev mai curr->left dalo
                TreeNode* prev = curr->left;

                // step 5 : same as Morris preorder to reach the rightmost LST
                // node
                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Step 6 : now ab prev-> right ko curr-> right se assign kara
                // do + curr->right ko left se to move to other node of LST

                // now prev->right == NULL
                prev->right = curr->right;
                curr->right = curr->left;

                // step 7 : hr node ke left ko NULL krte chalo -> as asked in
                // que to do so
                curr->left = NULL;
            }

            // step 8 : ab right pointer which is assigned to left -> now follow
            // left pointer by moving left
            curr = curr->right;

        }
        }
    };