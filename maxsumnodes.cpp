#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* left,*right;
        Node(int x) : data(x) , left(0) , right(0) {
        }
};

int calc(Node *root, map<Node*,int> &h) {
    if(root==0) return 0;
    if(h[root]) return h[root];
    int sum = root->data;
    if(root->left) sum += calc(root->left->left,h) + calc(root->left->right,h);
    if(root->right) sum += calc(root->right->left,h) + calc(root->right->right,h);
    return h[root] = max(sum , calc(root->left,h) + calc(root->right,h));
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    map<Node*,int> h;
    cout << calc(root,h) << endl;
}