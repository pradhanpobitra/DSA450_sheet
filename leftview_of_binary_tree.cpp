vector<int> ans;
void preorder(Node *root,int &mxlevel,int currlevel) {
    if(root==0) return;
    if(currlevel > mxlevel) {
        mxlevel = currlevel;
        ans.push_back(root->data);
    }
    preorder(root->left,mxlevel,currlevel+1);
    preorder(root->right,mxlevel,currlevel+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   ans.clear();
   int mxlevel = 0;
   preorder(root,mxlevel,1);
   return ans;
}