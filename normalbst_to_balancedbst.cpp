#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x) : data(x) , left(0) , right(0) {}
};

void flatten(Node* root,Node *&head,Node **prev) {
    if(root==0) return;
    flatten(root->left,head,prev);
    if(head==0) 
    {
        head = root;
        *prev = head;
    }
    else {
        root->left = *prev;
        (*prev)->right = root;
        *prev = root;
    }
    flatten(root->right,head,prev);
}
int count(Node *head) {
    int n = 0;
    while(head) {
        n++;
        head = head->right;
    }
    return n;
}
Node* turnOver(Node *&head,int n) {
    if(n <= 0) return NULL;

    Node *l = turnOver(head,n/2);
    head->left = l;
    l = head;
    head = head->right;
    l->right = turnOver(head,n- n/2 - 1);
    return l;
}
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int x = q.size();
        while(x--) {
            Node *t = q.front();
            q.pop();
            cout << t->data << " ";
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        cout << endl;
    }
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    cout << "before transformation : \n";
    levelOrder(root);
    Node *head = nullptr;
    Node *prev;
    flatten(root,head,&prev);
    int n = count(head);
    root = turnOver(head,n);
    cout << "\n after transformation : \n";
    levelOrder(root);
}