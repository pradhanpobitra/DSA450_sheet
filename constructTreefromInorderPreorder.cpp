Node* build(int in[],int pre[],int ps,int pe,int is,int ie) {
    if(pe < ps) return nullptr;
    Node *root = new Node(pre[ps]);
    for(int i=is;i <= ie;i++) {
        if(pre[ps] == in[i]) {
            root->left = build(in,pre,ps+1,ps+1+i-1-is,is,i-1);
            root->right = build(in,pre,ps+1+i-is,pe,i+1,ie);
            break;
        }
    }
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    //add code here.
    Node *root = build(in,pre,0,n-1,0,n-1);
    return root;
}