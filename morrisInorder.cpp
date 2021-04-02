#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x) : data(x) , left(0) , right(0) {}
};

Node* inorderPredecessor(Node *root) {
    Node *t = root->left;
    while(t->right && t->right!=root) t = t->right;
    return t;
}

int MorrisTraversal(Node *root) {
    int c = 0;
    while(root) {
        if(!root->left)  {
            // cout << root->data << " ";
            c++;
            root = root->right;
        }
        else {
            Node *t = inorderPredecessor(root);
            if(t->right==0) {
                t->right = root;
                root = root->left;
            }
            else {
                t->right = 0;
                // cout << root->data << " ";
                c++;
                root = root->right;
            }
        }
    }
    return c;
}

void solve(Node* root,int &ans,int n) {
    int c = 0;
    while(root) {
        if(!root->left) {
            c++;
            if(c==n) {
                ans = root->data;
                return;
            }
            root = root->right;
        }
        else {
            Node *t = inorderPredecessor(root);
            if(t->right==0) {
                t->right = root;
                root = root->left;
            }
            else {
                t->right = 0;
                c++;
                if(c==n) {
                    ans = root->data;
                    return;
                }
                root = root->right;
            }
        }
    }
}

int main() {
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    int n = MorrisTraversal(root);
    if(n%2) {
        n++;
        n /= 2;
        int ans;
        solve(root,ans,n);
        cout << ans << endl;
    }
    else {
        int a , b;
        solve(root,a,n/2);
        solve(root,b,n/2 + 1);
        float ans = (float) (a + b) / 2;
        cout << ans << endl;
    }
}