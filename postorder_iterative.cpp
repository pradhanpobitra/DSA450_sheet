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
    stack< pair<node*,bool> > st;
    st.push(mp(root,false));
    while(!st.empty()) {
        auto t = st.top();
        st.pop();
        if(t.second) {
            cout << t.first->data << " ";
            continue;
        }
        st.push(mp(t.first,true));
        if(t.first->right) st.push(mp(t.first->right,false));
        if(t.first->left) st.push(mp(t.first->left,false));
    }
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