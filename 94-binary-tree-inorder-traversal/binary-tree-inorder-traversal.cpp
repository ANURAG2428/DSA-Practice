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

    void helper(TreeNode* root , vector<int>&v){
        if(root == NULL) return; // simply backtrack

        helper(root->left,v);    // move left
        v.push_back(root->val);  // push the value into vector
        helper(root->right,v);   // move right

    }


    vector<int> inorderTraversal(TreeNode* root) {
        // will create a helper func which will perform InorderTraversal on the
        // vector we are gonna create in this func
        vector<int> v;
        helper(root, v);
        return v;
    }
};