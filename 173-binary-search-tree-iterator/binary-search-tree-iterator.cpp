/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    // step 1 : create a stack which will help in storing leftmost elmeent of root and will help us to get the root node and to proced to right's leftmost nodes
    stack<TreeNode*>st;


    BSTIterator(TreeNode* root) {  // parameterized constructor
        pushAll(root);    
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop(); // remove top most stack node 
        if(temp->right != NULL){
            pushAll(temp->right);  // now ab left ke baad root to print hogya hai -> we know in inorder traversal ab (Left , Root ) ke baad right aata hai so -> will explore right subtreee all left node if present to correctly iterate over in inorder way in BST 
        }
        return temp->val;
    }
    
    bool hasNext() {  // agr to stack empty hai to return false karenge , means inorder traversal over will return false , else abhi stack mai node's hai -> means inorder traversal pending
        return !st.empty();
    }
    private:
    void pushAll(TreeNode* root){
        while(root!=NULL ){
            st.push(root);
            root = root->left;
        }

    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */