/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void SerializeString(TreeNode* root, string& ans) {
        // B.C.C : agr root == NULL means add N with comma
        if (root == NULL) {
            ans = ans + "N,";
            return;
        }

        // step 1 : curr node ka data store karao wiht ","
        ans += to_string(root->val) + ",";

        // step 2 : serialize left subtree
        SerializeString(root->left, ans);
        // step 3 : serialize right subtree
        SerializeString(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        SerializeString(root, ans);
        return ans;
    }

    // Helper function which will help to reconstruct Binary Tree from serialize
    // data -> stored in q-> queue
    TreeNode* BuildTree(queue<string>& q) {
        // step 1 : take front value from queue
        string val = q.front();
        // step 2 : now ab q.front() ko pop() kra de
        q.pop();

        // B.C.C
        if (val == "N")
            return NULL;

        // step 3 : agr B.C.C false hai -> then string value ko int mai conver
        // kara ke root bna ke uske left and right ke liye same above process
        // call kr de via recursion
        TreeNode* root = new TreeNode(stoi(val));

        root->left = BuildTree(q);
        root->right = BuildTree(q);

        return root;
    }

    /* 
    VV IMP - "Ab ye returned string (jo pehle ans thi), direct deserialize function ke pehle argument (jo string data hai) mein daal di jaati hai.
    
    -deserialize ko pata nahi hota ki string ka naam kya tha. Compiler ne serialize ke return value ko copy karke deserialize ke data parameter mein daal diya. Naam se farak nahi padta, value se padta hai. 🚀
    "
     */

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // step 1 : using stringstream put each string element before ',' to be
        // pushed in queue -> ek baari mai
        queue<string> q;
        stringstream ss(
            data);   // here mene stringstream mai ans string daal di -> kyoki
                     // mujhe ans string mai se data extract krna hai
        string item; // here item string each time will have a node->data which
                     // will get pushed to queue in pre-order way -> the way in
                     // which serialize string is stored

        // NOTE - ek bari mai sare node-value one by one queue mai push kardunga
        while (getline(ss, item, ',')) {
            q.push(item);
        }

        // NOTE - ab above queue jisme string stored hai of each node->data uski
        // help se Binary tree bna lunga
        return BuildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));