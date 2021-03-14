bool getPath(int n,Node *root,vector<Node*> &path) {
    if(root==0) return false;
    path.push_back(root);
    if(root->data == n) return true;
    if(getPath(n,root->left,path)) return true;
    if(getPath(n,root->right,path)) return true;
    path.pop_back();
    return false;
}
class Solution
{
    public:
    Node* lca(Node* root,int n1,int n2)
    {
       //Your code here 
       vector<Node*> a,b;
       getPath(n1,root,a);
       getPath(n2,root,b);
       if(a.size()==0) return nullptr;
       Node *t = a[0];
       int na = a.size() , nb = b.size();
       for(int i=1;i<na && i < nb;i++) {
           if(a[i]!=b[i]) return t;
           t = a[i];
       }
       return t;
    }
};