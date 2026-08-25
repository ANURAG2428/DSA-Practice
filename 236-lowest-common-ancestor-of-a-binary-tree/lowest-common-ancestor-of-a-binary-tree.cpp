/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            // B.C.C  -> ye niche ke 2 b.c.c recursive call hone se pehle chal rhe hai taaki agr root node hi NULL hai to return NULL , ya to root node ki p ya q mai se kuch hai to sidha return that root
    if(root == NULL) return NULL;  // This also cover when hm DFS ke left most node pai hai which is NULL to -> vo NULL return karega
    
    
    // B.C.C -> agr root -> p ya q mai se kuch hai to return root
    if(root->val == p->val || root->val == q->val) return root;  // This also cover ki Recursive call krte hue koi bhi root ka data p ya q ke equal hai, hm further traverse na krke root ko return kra denge  
    
    
    
    // Recursive Calls
    TreeNode* leftResult = lowestCommonAncestor(root->left , p , q );
    TreeNode* rightResult = lowestCommonAncestor(root->right , p , q);

    /* 
    NOTE - ye niche wale B.C.C vo hai jb dono left and right recursive call execute ho chuki hai -> now ab ye dono LST and RST ki recursive call root ko kuch na kuch return krengi
    */


    // Now ab recursive call puri chal chki hai 
    if(leftResult!=NULL && rightResult !=NULL){
        return root; // means ab dono LST and RST tree ne jo result return kr rhe ahai to the root are both NOT NULL -> will simply return root
    }
    if(leftResult != NULL && rightResult == NULL ){  // means RST NULL return kr rha hai
        return leftResult;
    }
    if(rightResult != NULL && leftResult == NULL){  // means LST NULL return kr rha hai
        return rightResult;
    }
    else{
        return NULL; // Means dono hi NULL hai to root ko NULL hi return karenge
    }
    }
};