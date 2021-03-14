#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left,*right;
        Node(int x) : data(x) , left(0) , right(0) {

        }
};
void createPath(Node *root,vector<int> &path,int curr,int k,vector<vector<int>> &ans) {
    if(root==0) return;
    path.push_back(root->data);
    curr += root->data;
    if(curr == k) ans.push_back(path);
    createPath(root->left,path,curr,k,ans);
    createPath(root->right,path,curr,k,ans);
    path.pop_back();
}
void preorder(Node *root,vector<vector<int>> &ans,int k,vector<int> &path) {
    if(root==0) return;
    createPath(root,path,0,k,ans);
    preorder(root->left,ans,k,path);
    preorder(root->right,ans,k,path);
}
int main() {
    Node *root = new Node(1); 
    root->left = new Node(3); 
    root->left->left = new Node(2); 
    root->left->right = new Node(1); 
    root->left->right->left = new Node(1); 
    root->right = new Node(-1); 
    root->right->left = new Node(4); 
    root->right->left->left = new Node(1); 
    root->right->left->right = new Node(2); 
    root->right->right = new Node(5); 
    root->right->right->right = new Node(2); 
    vector<vector<int>> ans;
    vector<int> path;
    preorder(root,ans,5,path);
    for(vector<int> x : ans) {
        for(int y : x) cout << y << " ";
        cout << endl;
    }
}