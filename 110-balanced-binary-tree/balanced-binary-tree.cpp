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
    pair<bool, int> BalancedBinaryTree(TreeNode* root) {

        // Base Case Condition
        if (root == NULL) {
            return {true, 0}; // kyoki leaf node hamesha balanced hoga + uski
                              // height hmesah 0 hogi
        }

        pair<bool, int> left = BalancedBinaryTree(root->left);

        // now check here ki mera leaf node se aaya result true hai ya false
        if (!left.first)
            return {false, 0}; // Mere andar ka subtree unbalanced mil gaya hai.
                               // Ab aage height calculate karne ki zaroorat
                               // nahi hai, kyunki poora tree already unbalanced
                               // hai (so height hm 0 return kr rhe hai)

        pair<bool, int> right = BalancedBinaryTree(root->right);
        // same check for right also
        if (!right.first)
            return {false, 0}; // same as above explanation

        // Now dono recursive call hogai puri ab jo inse mujhe left aur right
        // subtree ki height mili hai unke base pai currNode check kro balanced
        // hai + uski height kya hai
        bool currNode = abs(left.second - right.second) <= 1;
        int currheight = 1 + max(left.second, right.second);

        // ab us particual node ke ye pair data stucture return krdo to pair
        // node
        return {currNode, currheight};
    }

    bool isBalanced(TreeNode* root) { 
        return BalancedBinaryTree(root).first; }
};