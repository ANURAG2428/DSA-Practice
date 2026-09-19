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
    // global variable
    int maxsum = 0;

    // createad a class which will return custom format return type that will
    // help in recursion function call return
    class Info {
    public:
        int minVal; // subtree ka minimum
        int maxVal; // subtree ka maximum
        int sum;    // subtree ka total sum
        bool isBST; // subtree BST hai ya nahi
    };

    Info dfs(TreeNode* root) {
        // B.C.C = null node
        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0, true};
        }

        // Now do post order traversal first to get the info about node ->
        // childern , then only i can pass on weather this is BST , maxlST value
        // , min RST value , to upper tree while backtracking
        Info left = dfs(root->left);
        Info right = dfs(root->right);

        // check karo current subtree BST hai ya nhi
        bool isCurrentBST = left.isBST && right.isBST &&
                            left.maxVal < root->val &&
                            right.minVal > root->val;

        // if ye particular node(root) bst hai , then iska sum calculate karo
        // and maxsum update karo and then minvalue and maxcalue with currsum
        // and bst status return karo to upper node while backtracking ,
        // otherwise NULL node wali same return type hoga curr node ka

        if (isCurrentBST) {
            int currsum = left.sum + right.sum + root->val;
            maxsum = max(maxsum, currsum);

            return {min(root->val, left.minVal), max(root->val, right.maxVal),
                    currsum, true};
        } else {
            // BST ni hai , parent isse ignore karega
            return {INT_MIN, INT_MAX, 0, false};
        }
    }

    int maxSumBST(TreeNode* root) {
        maxsum = 0;
        dfs(root);
        return maxsum;
    }
};