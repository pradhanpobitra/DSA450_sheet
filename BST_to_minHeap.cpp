#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left,*right;
        Node(int x) : data(x) , left(0) , right(0) {}
}; 

void inorder(Node* root,queue<int> &q) {
    if(root==0) return;
    inorder(root->left,q);
    q.push(root->data);
    inorder(root->right,q);
} 

void preorder(Node* root,queue<int> &q) {
    if(root==0) return;
    root->data = q.front();
    q.pop();
    preorder(root->left,q);
    preorder(root->right,q);
} 

void print(Node *root){
    if(root==0) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main() {
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    queue<int> q;
    inorder(root,q);
    print(root);
    cout << endl;
    
    preorder(root,q);
    print(root);
}