class Solution
{
    public:    
    void inorder(Node* root,Node** head,Node **previous) {
        if(root==0) return;
        inorder(root->left,head,previous);
        if(*head==0) {
            *head = root;
            *previous = *head;
        }
        else{
            (*previous)->right = root;
            root->left = *previous;
            *previous = root;
        }
        inorder(root->right,head,previous);
    }
    Node* bToDLL(Node* root)
    {
        // your code here
        Node* head = 0;
        Node* previous = 0;
        inorder(root,&head,&previous);
        return head;
    }
};