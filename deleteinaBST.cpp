class Solution {
  public:
    pair<TreeNode*,TreeNode*> inpre(TreeNode *root) {
        TreeNode *a,*b;
        a = root->left;
        b = a->right;
        while(a->right && b->right) {
            a = b;
            b = b->right;
        }
        pair<TreeNode*,TreeNode*> p;
        p = make_pair(a,b);
        return p;
    }
    TreeNode* deleteKey(TreeNode *root,int key) {
        
        if(root->val < key) root->right = deleteKey(root->right,key);
        else if(root->val > key) root->left = deleteKey(root->left,key);
        else {
            if(root->left && !root->right) return root->left;
            else if(root->right && !root->left) return root->right;
            else if(!root->left && !root->right) return nullptr;
            else {
                pair<TreeNode*,TreeNode*> p = inpre(root);
                if(!p.second) {
                    root->val = root->left->val;
                    root->left = root->left->left;
                    return root;
                }
                else {
                    root->val = p.second->val;
                    p.first->right = deleteKey(p.second,p.second->val);
                }
            }
        }
        return root;
    }
    bool search(TreeNode *root,int key) {
        if(root==0) return false;
        if(root->val == key) return true;
        if(root->val < key) return search(root->right,key);
        return search(root->left,key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(search(root,key)) return root = deleteKey(root,key);
         return root;
    }
};