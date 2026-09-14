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
    TreeNode* prevNode = NULL;
    bool isValidBST(TreeNode* root) {
        // step 1 : it handle's both case either of LST or RST of a node is NULL
        // then will return true + if the root node of BST is NULL is that case
        // also its a valid BST
        if (root == NULL)
            return true;

        // step 2 : idhr maine return validBST(root->left) => isley nhi likha
        // bcz "Isliye: Left se agar false aaya, toh turant false return karo.
        // Agar true aaya, toh rukna nahi hai — current node check karo, phir
        // right subtree check karo."
        if (!isValidBST(root->left))
            return false;
        /*
        if(!ValidBST(root->left)) return false; ka matlab: "Left subtree invalid
        hai toh poora tree invalid, turant false. Warna aage check karo." Ye
        early exit hai, taaki invalid case mein time bache.
        */

        // step 3 : agr mera ab jo root node hai vo agr mere prev store node*
        // pointer mai present node ki value se chota hai -> means ascending
        // sorted order of BST is distrupted means -> this BST is not valid BST
        // -> will return false
        if (prevNode != NULL && prevNode->val >= root->val)
            return false;

        // step 4 : chahe kuch bhi ho hm beech tree ke recursive traversing ko
        // break kara ke ans nhi return kr skte to hr baar prev bhi update hoga
        // -> will traverse whole tree
        prevNode = root;

        // step 5 : now following the inorder traversal will move right after
        // (Left, Root , ..)
        return isValidBST(root->right);
    }
};