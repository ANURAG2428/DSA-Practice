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
    bool SymmetricTree(TreeNode* leftp, TreeNode* rightp) {

        // BCC - 1
        if (leftp == NULL &&
            rightp == NULL) { // leftp aur rightp to khud node hai agr whi NULL
                              // hogye recursive calll se then
            return true;
        }

        // BCC - 2 (means above if true nhi hai -> means dono pointer mai se koi
        // ek pointer NULL nhi hai tabhi upr wlaa true nhi hua -> so mai return
        // false kara dunga is BCC se)
        if (leftp == NULL || rightp == NULL) {
            return false;
        }

        /*
            IMP NOTE - agr mai Data ko direct match krne pai return true kara
           dunga , to niche ka Tree check hi nhi hoga -> Recursion basically DFS
           hai niche tk jata hai and then backtrack krte hue True/false ya value
           return krta hai

            if(leftp->data == rightp->data){
                return true;
            }
        */

        // IMP - Instead of above as base case -> mera ye base case ho skta hai
        // ki the moment mere leftp->data != rightp->data then mai ussi samay
        // false return kr skta hu aur niche ka tree further traverse nhi hoga
        // and mera jo Recursive call ke niche return hai vo then further
        // backtrack krte hue int main ko false return kara dega because there
        // we are using &&

        if (leftp->val != rightp->val)
            return false;

        // Recursive Calls
        bool left = SymmetricTree(leftp->left, rightp->right);
        bool right = SymmetricTree(leftp->right, rightp->left);

        return (left && right);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == NULL) {
            return true; // empty tree is considred as symmetric tree
        }

        TreeNode* leftp = root->left;
        TreeNode* rightp = root->right;

        // No need to check here about leftp and rightp , vo recursive function
        // mai recursive calls chalne se pehle hi khud check ho jayega

        bool result = SymmetricTree(leftp, rightp);
        return result;
    }
};