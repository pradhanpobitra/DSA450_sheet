#include <bits/stdc++.h>
using namespace std;

int solve(Node *node)
{
    if (node->left == 0 && node->right == 0)
    {
        int ans = node->data;
        node->data = 0;
        return ans;
    }
    else if (node->left == 0)
    {
        int k = solve(node->right);
        int ans = node->data + k;
        node->data = k;
        return ans;
    }
    else if (node->right == 0)
    {
        int k = solve(node->left);
        int ans = node->data + k;
        node->data = k;
        return ans;
    }
    int l = solve(node->left);
    int r = solve(node->right);
    int ans = node->data + l + r;
    node->data = l + r;
    return ans;
}

void toSumTree(Node *node)
{
    // Your code here
    solve(node);
}