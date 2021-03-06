#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : left(0) , right(0) {
        }
};
int converttoint(string &num) {
    int data = 0;
    for(char c : num) {
        data = data * 10 + (c - '0');
    }
    return data;
}
TreeNode* constructTree(string &s,int start,int end) {
    TreeNode *root = new TreeNode();
    string num;
    int i=start;
    while(s[i]!='(' && i <= end) num.push_back(s[i++]);
    root->val = converttoint(num);
    if(i <= end) {
        stack<int> st;
        while(i <= end) {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')') {
                int x = st.top();
                st.pop();
                if(st.empty()) {
                    if(root->left==0) root->left = constructTree(s,x+1,i-1);
                    else root->right = constructTree(s,x+1,i-1);
                }
            }
            i++;
        }
    }
    return root;
}
void preorder(TreeNode *root) {
    if(root==0) return;
    cout << root->val <<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    string s;
    cin >> s;
    TreeNode *root = constructTree(s,0,s.length()-1);
    preorder(root);
}