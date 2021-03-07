int see(Node* root,bool &is) {
    if(root->left==0 && root->right==0) return root->data;
    int sum = 0;
    if(root->left) sum += see(root->left,is);
    if(root->right) sum += see(root->right,is);
    if(sum != root->data) is = false;
    return sum + root->data;
}
bool isSumTree(Node* root)
{
     // Your code here
     if(root==0) return true;
     bool is = true;
     see(root,is);
     return is;
}