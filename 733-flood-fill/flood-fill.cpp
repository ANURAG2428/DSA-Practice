/*

Optimized Approch : Explained In Register

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    void DFS(int sr, int sc, vector<vector<int>>& image,
             vector<vector<int>>& vis, int color, vector<int>& delRow,
             vector<int>& delCol, int orgval, int n, int m) {

        // step 1 : given sr, sc node ko color se assign karo
        vis[sr][sc] = color;

        // step 2 : ab iske neighbours check kro , agr to unki value == orgval
        // -> then call DFS for them , else don't call

        for (int d = 0; d < 4; d++) {
            int nrow = sr + delRow[d];
            int ncol = sc + delCol[d];

            // step 3: now if condition true , then only call DFS
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == orgval && vis[nrow][ncol] != color) {
                DFS(nrow, ncol, image, vis, color, delRow, delCol, orgval, n,
                    m);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // Step 1 : lets firstly store the original starting index value in a
        // varible , which will be further used during traversal
        int orgval = image[sr][sc];
        int n = image.size();    // for row
        int m = image[0].size(); // for col

        if (image[sr][sc] == color)
            return image; // no need to do DFS

        // Step 2 : now ab ek aur 2d Matrix exactly same as image bna , jisme hm
        // changes kareneg , bcz i don't want to do chanegs in original image
        // matrix
        vector<vector<int>> vis = image;

        // Step 3 : now for starting index , lets call DFS , with DelRow and
        // DelCol , used in checking neighbour of each node in matrix
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        DFS(sr, sc, image, vis, color, delRow, delCol, orgval, n, m);

        return vis;
    }
};