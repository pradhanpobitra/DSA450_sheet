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
void preorder(node *root) {
    stack<node*> st;
    st.push(root);
    while(!st.empty()) {
        node *t = st.top();
        st.pop();
        cout << t->data << " ";
        if(t->right) st.push(t->right);
        if(t->left) st.push(t->left);
    } 
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