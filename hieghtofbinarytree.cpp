#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(Node *root, int &mxheight, int currheight)
    {
        if (root == 0)
            return;
        mxheight = max(mxheight, currheight);
        solve(root->left, mxheight, currheight + 1);
        solve(root->right, mxheight, currheight + 1);
    }
    int height(struct Node *node)
    {
        // code here
        int mxheight = 0;
        if (node == 0)
            return 0;
        int currheight = 1;
        solve(node, mxheight, currheight);
        return mxheight;
    }
};