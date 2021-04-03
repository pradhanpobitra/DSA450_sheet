#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left,*right;
        node(int x) : data(x) , left(0) , right(0) {}
};

void inorder(node *root,node *&head,node *&prev) {
    if(root==0)  return;
    inorder(root->left,head,prev);
    if(!head) {
        head = root;
        prev = root;
    }
    else {
        prev->right = root;
        root->left = prev;
        prev = root;
    }
    inorder(root->right,head,prev);
}
void print(node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->right;
    }
}
int main() {
    node *head = 0 , *prev;
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
    inorder(root,head,prev);
    print(head);
}