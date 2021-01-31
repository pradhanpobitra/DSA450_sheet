#include <bits/stdc++.h>
using namespace std;

int solve(Node *root, int &dia)
{
    if (root == 0)
        return 0;
    // if(root->left==0 && root->right==0) return 1;
    int lh = solve(root->left, dia);
    int rh = solve(root->right, dia);
    dia = max(dia, 1 + lh + rh);
    return 1 + max(lh, rh);
}
int diameter(Node *root)
{
    // Your code here
    int dia = 0;
    if (root == 0)
        return 0;
    solve(root, dia);
    return dia;
}