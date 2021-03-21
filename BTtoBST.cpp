void inorder(Node *root,vector<int> &v) {
    if(root==0) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
void replace(Node *root,vector<int> &v,int &i) {
    if(root==0) return;
    replace(root->left,v,i);
    root->data = v[i];
    i++;
    replace(root->right,v,i);
}
Node *binaryTreeToBST (Node *root)
{
    //Your code goes here
    vector<int> v;
    inorder(root,v);
    sort(v.begin(),v.end());
    int i=0;
    replace(root,v,i);
    return root;
}
