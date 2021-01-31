#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    ;
    Node()
    {
        left = right = NULL;
    }
    Node(int x) : data(x), left(0), right(0)
    {
    }
};
void solve(Node *root, Node *mirror)
{
    if (root->left)
    {
        mirror->right = new Node(root->left->data);
        solve(root->left, mirror->right);
    }
    if (root->right)
    {
        mirror->left = new Node(root->right->data);
        solve(root->right, mirror->left);
    }
}
Node *constructTreeMirror(Node *root)
{
    if (root == 0)
        return nullptr;
    Node *mirrorTree = new Node(root->data);
    solve(root, mirrorTree);
}