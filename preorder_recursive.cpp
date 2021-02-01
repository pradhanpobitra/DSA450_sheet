#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node *left,*right;
        node(int x) : data(x) , left(0) , right(0) {

        }
};

void preorder(node* root) {
    if(root==0) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    node *root = new node(5);
    root->left = new node(7);
    root->right = new node(9);
    root->left->left = new node(10);
    root->right->left = new node(12);
    root->right->right = new node(13);
    preorder(root);
}