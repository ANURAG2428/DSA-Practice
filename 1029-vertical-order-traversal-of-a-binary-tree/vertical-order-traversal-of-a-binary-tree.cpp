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
    void FunctionToStoreMapElement(TreeNode* root,
                                   map<int, vector<pair<int, int>>>& mpp,
                                   int row, int col) {

        // B.C.C
        if (root == NULL)
            return;

        // since mera mpp ka type hai (int , vector{pair<int,int>}) -> that's
        // why mene us col ki value jo ki vector type ki hai usme ye pair add
        // karaya ese
        mpp[col].push_back({row, root->val});
        FunctionToStoreMapElement(root->left, mpp, row + 1, col - 1);
        FunctionToStoreMapElement(root->right, mpp, row + 1, col + 1);
    }

    vector<vector<int>>
    VerticalOrderTraversal(TreeNode* root, map<int, vector<pair<int, int>>>& mpp) {

        // step 0: create kr ek 2D array which will store the vertical order
        // traversal
        vector<vector<int>> ans;

        // step 1 : as we know ki map sorted order mai present acc to col
        for (auto it : mpp) { // taking each element 1 time from map (which are
                              // arranged in sorted order)

            // here vec -> symbolize vector containing pair of {row, node->data}
            auto& vec =
                it.second; // kyoki agr mere col se more that 1 pair assign hai
                           // so ek tarike se vector mai multiple pair honge ,
                           // to mujhe un pair ko sorted order mai arrange krna
                           // hai firslt then uki value of 2d vector mai dalunga

            // step 2 : ab mujhe agr kisi col ke pass mutliple pari hai to unhe
            // sort krna hai -> so will use custom comprator (bcz built in func
            // to hai nhi mere pass koi)
            sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
                // firstly check agr row d/f hai to row ke base pai sort krde
                if (a.first != b.first)
                    return a.first < b.first;

                // if row same hai to node->data ke base pai sort krde
                return a.second < b.second;
                // NOTE - yhi agr dec order mai sort krna hai to sign ulta ho
                // jayega
            });

            // step 3 : create kr ek vector jisme mai curr element ke data ko
            // store karunga , agr single node assign tha kisi ko col ko tb bhi
            // loop chalega agr multiple the tb bhi loop chalega

            vector<int> colValues;
            for (auto& p : vec) {
                colValues.push_back(p.second);
            }

            // step 4 : ab mere colValues vector mai is "it" particular col ke
            // sare pair ke node->data sorted way mai store ho gye hai -> now ab
            // mai is colValues ko ans 2d vector mai push kara dunga
            ans.push_back(colValues);
        }

        // step 5 :simply return ans 2d vector
        return ans;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // here i want to store vertical order traversal
        vector<vector<int>> ans;
        // create map which will store all node col -> {row,value} coloumn wise
        map<int, vector<pair<int, int>>> mpp; // as it is map which will store
                                              // this custom element in col wise

        // EDGE CASE
        if (root == NULL) {
            return {};
        }

        // Function to store custom elements in map of its type
        FunctionToStoreMapElement(root, mpp, 0, 0);

        // Function to simply store all the node with required condition of
        // vertical order travesal
        return VerticalOrderTraversal(root, mpp);
    }
};