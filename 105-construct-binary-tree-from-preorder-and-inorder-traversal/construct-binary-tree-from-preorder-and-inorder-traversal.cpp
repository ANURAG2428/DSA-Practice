/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Global index for preorder traversal
    int preIdx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIdx = 0;
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& pre, vector<int>& In, int s, int e) {
        if (s > e) return NULL;

        // Step 1: Create root node from preorder
        TreeNode* root = new TreeNode(pre[preIdx++]);

        // Step 2: Find root in inorder
        int i;
        for (int j = s; j <= e; j++) {
            if (In[j] == root->val) {
                i = j;
                break;
            }
        }

        // Step 3: Recursively build left and right subtrees
        root->left = buildTreeHelper(pre, In, s, i - 1);
        root->right = buildTreeHelper(pre, In, i + 1, e);

        return root;
    }
};