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
    // This function basically calculate's LST height of curr root
    int getLeftHeight(TreeNode* root) {
        int h = 0;
        TreeNode* temp = root;
        while (temp) {
            h++; // current existing node ki height 1 mani jayegi
            temp = temp->left;
        }

        return h;
    }

    // This function basically calculate's RST height of curr root
    int getRightHeight(TreeNode* root) {
        int h = 0;
        TreeNode* temp = root;
        while (temp) {
            h++; // current existing node ki height 1 mani jayegi
            temp = temp->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {

        if (root == NULL)
            return 0;

        /*
        Now ab -> mai hr node ki left and right height dekhunga agr to same hai
        means its perfect binary tree -> to no of nodes will be 2^h-1 , else agr
        height same nhi hai then no of nodes -> 1 + (total no nodes in LST) +
        (total no nodes in RST)
        */

        // Recursive Relations
        int LSTht = getLeftHeight(root);
        int RSTht = getRightHeight(root);

        //  Case 1: Perfect tree mil gaya

        // Height same -> measn its a perfect binary tree and we know total no
        // of nodes in perfect binary tree is = 2^h-1;
        if (LSTht == RSTht) {
            return (1 << LSTht) -
                   1; // Int Overflow? -> ht maximum ~16-17 hoti hai is problem
                      // mein (kyunki nodes 10^4 hain), toh 1 << 17 = 131072, jo
                      // int mein aaram se aa jaata hai. (Agar ht 31 se zyada
                      // ho, toh 1LL << ht use karo, par yahan zaroorat nahi).
        }

        //  Case 2: Perfect nahi hai, toh left aur right mein dhoondho

        // means LST ht != RST ht (then total no of node is = 1 + (no of node in
        // LST ) + (no of nodes in RST))

        /* So mujhe LST mai no of nodes chahiye and total no of RST mai , so mai
         * LST aur RST ke liye same func call kr dunga  */
        return 1 + countNodes(root->left) +
               countNodes(root->right);
    }
};