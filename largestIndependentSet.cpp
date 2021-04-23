#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left,*right;
        Node(int x) {
            left = right = 0;
            data = x;
        }
};

pair<int,int> solve(Node *root) {
    pair<int,int> p,q,r;
    if(root==0) {
        p.first = 0;
        p.second = 0;
        return p;
    }
    p = solve(root->left);
    q = solve(root->right);
    r.first = 1 + p.second + q.second;
    r.second = max(p.first,p.second) + max(q.first,q.second);
    return r;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right->right = new Node(60);
    pair<int,int> p = solve(root);
    cout << max(p.first,p.second) << endl;
}