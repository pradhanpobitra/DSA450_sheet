bool solve(Node *root1,Node *root2) {
    if(!root1 && !root2) return true;
    if(root1 && !root2) return false;
    if(root2 && !root1) return false;
    if(root1->data != root2->data) return false;
    bool ans = ( solve(root1->left,root2->left) && solve(root1->right,root2->right) ) ||
               ( solve(root1->left,root2->right) && solve(root1->right,root2->left));
    return ans;
}
bool isIsomorphic(Node *root1,Node *root2)
{
    //add code here.
    bool ans = solve(root1,root2);
    return ans;
}