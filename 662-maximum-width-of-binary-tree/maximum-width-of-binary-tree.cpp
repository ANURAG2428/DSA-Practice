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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        unsigned long long ans =
            0; // to return int ans , ab mujhe alg se max built in func mai cast
               // nhi krna pdega (right-left+1) ko

        // step 1 : creata a queue which will store {node , index}
        queue<pair<TreeNode*, unsigned long long>> q;
        // step 2 : i will do indexing here from '0'
        q.push({root, 0});

        // now specify left most node and right most node for a level , that at
        // the end would help to calculate the maxwidth
        unsigned long long leftmost, rightmost;
        while (!q.empty()) {
            int size = q.size();

            unsigned long long min =
                q.front().second; // hr level ke liye hm leftmost node ke index
                                  // ko min manenge

            for (int i = 0; i < size; i++) {
                auto p = q.front();
                unsigned long long curr = q.front().second - min;
                if (i == 0)
                    leftmost = curr;
                if (i == size - 1)
                    rightmost = curr;

                // now just pop the current front node from qeueue and then
                // enter its left and right node if present
                q.pop();

                if (p.first->left != NULL)
                    q.push({p.first->left, 2 * curr + 1});
                if (p.first->right != NULL)
                    q.push({p.first->right, 2 * curr + 2});
            }
            // now mai curr level se bahr aagya lets calculate width of each
            // level and store max width in ans
            ans = max(ans, (rightmost - leftmost + 1));
        }
        return int(ans); // since mera func int type ka hai aur mai return
                         // "unsigned long long" type ka kr rha hu , isley mene
                         // isko int mai cast kr liya
    }
};