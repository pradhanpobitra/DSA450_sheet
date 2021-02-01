#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left,*right;
        node(int x) : data(x) , left(0) , right(0) {

        }
};

void inorder(node *root) {
    if(root==0) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    node *root = new node(5);
    root->left = new node(7);
    root->right = new node(9);
    root->left->left = new node(10);
    root->right->left = new node(12);
    root->right->right = new node(13);
    inorder(root);
}