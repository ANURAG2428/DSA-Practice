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
    struct Info {
        int mn, mx;
        int sum;
        bool isBST;

        Info(int mn, int mx, int sum, bool isBST)
            : mn(mn), mx(mx), sum(sum), isBST(isBST) {}
    };

    int ans = 0;

    Info solve(TreeNode* root) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0, true};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        // Current subtree is a BST if:
        // left subtree is BST
        // right subtree is BST
        // max(left) < root->val < min(right)
        if (left.isBST && right.isBST && left.mx < root->val &&
            root->val < right.mn) {

            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);

            return {min(left.mn, root->val), max(right.mx, root->val), sum,
                    true};
        }

        // Not a BST
        return {INT_MIN, INT_MAX, 0, false};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};