#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left,*right;
        Node(int x) : data(x) , left(0) , right(0) {}
};

void flatten(Node *root,Node *&head,Node *&prev) {
    if(root==0) return;
    flatten(root->left,head,prev);
    if(!head) {
        head = root;
        prev = root;
    }
    else {
        prev->right = root;
        root->left = prev;
        prev = root;
    }
    flatten(root->right,head,prev);
}

Node* merge(Node *root1,Node *root2) {
    if(root1 && !root2) return root1;
    if(root2 && !root1) return root2;
    if(!root1 && !root2) return nullptr;
    if(root2->data < root1->data) swap(root1,root2);
    Node *head = root1, *prev = root1;
    root1 = root1->right;
    while(root1 && root2) {
        if(root1->data <= root2->data) {
            prev->right = root1;
            root1->left = prev;
            prev = root1;
            root1 = root1->right;
        }
        else {
            prev->right = root2;
            root2->left = prev;
            prev = root2;
            root2 = root2->right;
        }
    }
    if(root1) {
        prev->right = root1;
        root1->left = prev;
    }
    if(root2) {
        prev->right = root2;
        root2->left = prev;
    }
    return head;
}
int count(Node *head) {
    int n = 0;
    while (head)
    {
        /* code */
        n++;
        head = head->right;
    }
    return n;
}
Node* transform(Node *&head,int n) {
    if(n <= 0) return NULL;
    Node *lchild = transform(head,n/2);
    head->left = lchild;
    lchild = head;
    head = head->right;
    lchild->right = transform(head,n - n/2 - 1);
    return lchild;
}

void print(Node *root) {

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
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);

    cout <<" before : " << endl;
    print(root1);
    print(root2);

    Node *head1 = 0 , *head2 = 0;
    Node *prev;
    flatten(root1,head1,prev);
    flatten(root2,head2,prev);

    head1 = merge(head1,head2);

    int n = count(head1);
    root1 = transform(head1,n);
    cout << "after :" <<endl;
    print(root1);
}