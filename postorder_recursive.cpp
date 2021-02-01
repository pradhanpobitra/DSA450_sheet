#include<bits/stdc++.h>
using namespace std;
#define mp make_pair

class node{
    public:
        int data;
        node *left,*right;
        node(int x) : data(x) , left(0) , right(0) {

        }
};

void postorder(node *root) {
    if(root==0) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " " ;
}

int main() {
    node *root = new node(5);
    root->left = new node(7);
    root->right = new node(9);
    root->left->left = new node(10);
    root->right->left = new node(12);
    root->right->right = new node(13);
    postorder(root);
}