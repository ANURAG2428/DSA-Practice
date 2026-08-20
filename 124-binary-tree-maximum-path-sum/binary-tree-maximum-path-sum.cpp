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
    int MaxPathSum(TreeNode* root, int& sum) {

        // Base Case Condition
        if (root == NULL) {
            return 0;
        }

        int leftSum = max(0, MaxPathSum(root->left, sum));
        int rightSum = max(0, MaxPathSum(root->right, sum));

        // curr node ke through V shape path ka sum (left + right + Root)
        // isko recurive call right ke end hone ke just baad isley likha taaki
        // mera jo sbse nichee extreme left mai jo ulta v shape pair banega uska
        // sum store ho jaye currPathSum mai , taaki ye pair chute na
        int currPathsum = leftSum + rightSum + root->val;
        sum = max(currPathsum, sum);

        // now ab mujhe longest path nikalana hai -> so left and right mai se vo
        // path choose karunga -> jiska sum jada hoga (either left or right)

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        MaxPathSum(root, sum);
        return sum;
    }
};