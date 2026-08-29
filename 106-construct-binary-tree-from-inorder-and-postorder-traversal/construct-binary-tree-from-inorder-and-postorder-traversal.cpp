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
    int postIndx = 0;

    TreeNode* BuildTree(vector<int>& preorder, int left, int right,
                    unordered_map<int, int>& mpp) {

        if (left > right)
            return NULL;

        int rootvalue = preorder[postIndx--];

        TreeNode* root = new TreeNode(rootvalue);

        int mid = mpp[rootvalue];

        root->right = BuildTree(preorder, mid + 1, right, mpp);
        root->left = BuildTree(preorder, left, mid - 1, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> mpp;

        postIndx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return BuildTree(postorder, 0, inorder.size() - 1, mpp);
    }
};