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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        // Base Case Condition

        // agr dono NULL mai pahunch gye means yes both tree are identical
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        // ek root NULL pai pahunch gya aur ek nhi pahucha means identical nhi
        // hai
        if (root1 == NULL || root2 == NULL) {
            return false;
        }

        // check pehle isley likha kyoki pehle root node ko bhi compare krle ->
        // first then move to left and right
        bool check = (root1->val == root2->val);
        bool Checkleft = isSameTree(root1->left, root2->left);

        bool Checkright = isSameTree(root1->right, root2->right);

        return check && Checkleft && Checkright;
    }
};