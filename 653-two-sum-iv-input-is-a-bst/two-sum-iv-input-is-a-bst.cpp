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

    // step 1 : create 2 stack 1 for next() and 2nd for back()
    stack<TreeNode*> st1, st2;

    // step 2 : will create 2 class methods() -> which will basically store
    // extreme left most node from root and extreme rightmost node from root

    // METHOD 1 : for next()
    void pushleft(TreeNode* root) {
        while (root != NULL) {
            st1.push(root);
            root = root->left;
        }
    }
    // METHOD 2 : for back()
    void pushright(TreeNode* root) {
        while (root != NULL) {
            st2.push(root);
            root = root->right;
        }
    }

    // step 3 : write functionality of next() and back()

    int next() {
        TreeNode* temp1 = st1.top();
        st1.pop();
        if (temp1->right != NULL) {
            pushleft(temp1->right);
        }
        return temp1->val;
    }

    int back() {
        TreeNode* temp2 = st2.top();
        st2.pop();
        if (temp2->left != NULL) {
            pushright(temp2->left);
        }
        return temp2->val;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false; // not found 2 node whose value sum's to key

        // call pushleft() and pushright() to get to the 2 most extreme end of
        // BST
        pushleft(root);
        pushright(root);

        // now get the extreme node value via next() and back()
        int s = next();
        int e = back();

        while (s < e) {
            int sum = s + e;
            if (sum == k)
                return true;
            if (sum < k) {
                s = next(); // sum badhao
            } else {
                e = back(); // sum reduce karo
            }
        }
        return false;
    }
};