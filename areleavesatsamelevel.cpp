void solve(Node* root,bool &issame,bool &isset,int &level,int currlevel) {
    if(root==0) return;
    if(root->left==0 && root->right==0) {
        if(isset) {
            if(currlevel != level) {
                issame = false;
            }
        }
        else {
            level = currlevel;
            isset = true;
        }
        return;
    }
    solve(root->left,issame,isset,level,currlevel+1);
    solve(root->right,issame,isset,level,currlevel+1);
}
bool check(Node *root)
{
    //Your code here
    bool issame = true;
    bool isset = false;
    int level = 0;
    int currlevel = 1;
    solve(root,issame,isset,level,currlevel);
    return issame;
}