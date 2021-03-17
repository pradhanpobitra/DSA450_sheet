Node* insert(Node* root, int key)
{
    // Your code here
    if(root==0) {
        Node *t = new Node(key);
        return t;
    }
    if(root->data == key)  return root;
    if(key > root->data) root->right = insert(root->right,key);
    else root->left = insert(root->left,key);
    return root;
}