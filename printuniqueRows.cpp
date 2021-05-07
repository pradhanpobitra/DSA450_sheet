class TrieNode {
        public:
            int rowno;
            TrieNode *left,*right;
            TrieNode() : left(0) , right(0) { }
};
/*You are required to complete this function*/
void insert(TrieNode *root,vector<int> v,int row) {
    bool waspresent = true;
    for(int x : v) {
        if(x == 1) {
            if(!root->right) { waspresent = false; root->right = new TrieNode(); }
            root = root->right;
        }
        else {
            if(!root->left) { waspresent = false; root->left = new TrieNode(); }
            root = root->left;
        }
    }
    if(!waspresent) root->rowno = row;
    
}
void preorder(TrieNode *root,vector<int> &v,vector<pair<int,vector<int>>> &ans) {
    if(!root->left && !root->right) {
        ans.push_back(make_pair(root->rowno,v));
        return;
    }
    if(root->left) {
        v.push_back(0);
        preorder(root->left,v,ans);
        v.pop_back();
    }
    if(root->right) {
        v.push_back(1);
        preorder(root->right,v,ans);
        v.pop_back();
    }
}
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    TrieNode *root = new TrieNode();
    for(int i=0;i<row;i++) {
        vector<int> v;
        for(int j=0;j<col;j++) v.push_back(M[i][j]);
        insert(root,v,i);
    }
    vector<pair<int,vector<int>>> ans;
    vector<int> v;
    preorder(root,v,ans);
    sort(ans.begin(),ans.end());
    vector<vector<int>> a;
    for(auto x : ans) a.push_back(x.second);
    return a;
}