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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        // Edge Case :
        if (root == NULL)
            return ans; // means tree does not exist's

        queue<TreeNode*> q;
        q.push(root);
        bool leftoright = true; // true means level vector ko vese hi push_back
                                // krdo ans mai . If false means level vector ko
                                // reverse krke push_back krdo ans mai
        while (!q.empty()) {
            int size = q.size(); // curr -> level ke kitne node hai

            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop(); // pehe pop karenge phir new children  push karenege

                level.push_back(
                    curr->val); // pehle data push karo then children add kro
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }

            if (!leftoright) { // means odd index hai isme zig zag traversal ke
                               // liye reverse krke level vector ans mai push
                               // karao
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);

            // agr ye odd index nhi hai -> to next hoga isley leftoright ko
            // toggle krde
            leftoright = !leftoright; // Agle level ke liye flag toggle karo
        }
        return ans;
    }
};