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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>>
            mp; // map automatically col wise sorted

        // DFS traversal
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int col,
                                                      int row) {
            if (!node)
                return;
            mp[col].push_back({row, node->val});
            dfs(node->left, col - 1, row + 1);
            dfs(node->right, col + 1, row + 1);
        };
        dfs(root, 0, 0);

        vector<vector<int>> ans;
        for (auto& it : mp) {
            // Har column ke vector ko sort karo: pehle row, phir value
            auto& vec = it.second;
            sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
                if (a.first != b.first)
                    return a.first < b.first; // row
                return a.second < b.second;   // value
            });

            vector<int> colValues;
            for (auto& p : vec) {
                colValues.push_back(p.second);
            }
            ans.push_back(colValues);
        }
        return ans;
    }
};