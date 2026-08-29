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
    int preIndx = 0;

    TreeNode* BuildTree(vector<int>& preorder, int left, int right,
                    unordered_map<int, int>& mpp) {

        // step 1 : agr to mera left>right hogya means i have explored all value
        // -> will simply return NULL
        if (left > right)
            return NULL;

        // step 2 : lets take root->value from preorder vector and uska ek root
        // bana ke -> uske left aur right ke liye same process ke liye call kr
        // dete hai via Recursive call
        int rootvalue =
            preorder[preIndx++]; // yaha mene preIndx ki value increase krdi to
                                 // move at next root

        // step 3 : created a new node for the rootvalue
        TreeNode* root = new TreeNode(rootvalue);

        // ab mujhe rootvalue ka index nikal ke from the map -> which store indx
        // of inorder traversal -> ab mujhe curr rootvalue ke index ke liye uske
        // left and right node create kr kr unhe return karate hue tree form
        // krna hai
        int mid = mpp[rootvalue];

        // step 4 : Recursive calls
        root->left = BuildTree(
            preorder, left, mid - 1,
            mpp); // kyoki mujhe curr root ke left ka tree form krna hai
        root->right = BuildTree(preorder, mid + 1, right, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // step 1 : inorder vector ke node->value ko unke index se map kra de
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        // step 2 : now ab above map ko use krke "BuildTree()" func se using
        // preorder and inorder unique tree construct kr

        return BuildTree(preorder, 0, inorder.size() - 1, mpp);
    }
};