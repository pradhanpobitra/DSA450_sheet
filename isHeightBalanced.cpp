
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(0), right(0) {}
};
int solve(Node *root, bool &isbalanced)
{
    if (root == 0)
        return 0;
    int lh = solve(root->left, isbalanced);
    int rh = solve(root->right, isbalanced);
    if (abs(lh - rh) > 1)
        isbalanced = false;
    return 1 + max(lh, rh);
}
bool isBalanced(Node *root)
{
    //  Your Code here
    bool isbalanced = true;
    solve(root, isbalanced);
    return isbalanced;
}