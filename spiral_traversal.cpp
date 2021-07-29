#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        Node(int x = 0) {
            data = x;
            left = 0;
            right = 0;
        }
};

void spiral(Node* root) {
    cout << root->data << " ";
    deque<Node*> dq;
    Node* temp;
    dq.push_back(root);
    int turn = 0;
    while(!dq.empty()) {
        int n = dq.size();
        while(n--) {
            if( !turn ) {
                temp = dq.front();
                dq.pop_front();
                if(temp->left)  { cout << temp->left->data << " "; dq.push_back(temp->left); }
                if(temp->right) { cout << temp->right->data << " "; dq.push_back(temp->right); }
            }
            else {
                temp = dq.back();
                dq.pop_back();
                if(temp->right) { cout<<temp->right->data << " "; dq.push_front(temp->right); }
                if(temp->left) { cout << temp->left->data <<  " "; dq.push_front(temp->left);  }
            }
        }
        turn = 1 - turn;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    cout << "Spiral Order traversal of binary tree is \n";
    spiral(root);
}