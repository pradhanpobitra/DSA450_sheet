bool match(Node *root1,Node *root2) {
    queue<Node*> q1,q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()) {
        int x = q1.size();
        while(x--) {
            Node *p = q1.front();
            Node *q = q2.front();
            q1.pop();
            q2.pop();;
            ;;;;
            if(p->data != q->data) return false;
            if(p->left && !q->left) return false;
            if(p->right && !q->right) return false;
            if(!p->left && q->left) return false;
            if(!p->right && q->right) return false;
            if(p->left) {
                q1.push(p->left);
                q2.push(q->left);
            }
            if(p->right) {
                q1.push(p->right);
                q2.push(q->right);
            }
        }
    }
    return true;
}
bool check(Node *sub,Node *root) {
    if(root==0) return false;
    if(root==sub) return false;
    if(root->data == sub->data) {
        if(match(sub,root)) return true;
    }
    return check(sub,root->left) || check(sub,root->right);
}
void solve(Node* sub,Node *root,bool &isthere) {
    if(sub==0) return;
    if(sub->left==0 && sub->right==0) return;
    isthere = isthere || check(sub,root);
    solve(sub->left,root,isthere);
    solve(sub->right,root,isthere);
}
bool dupSub(Node *root)
{
     //your code here
    bool isthere = false;
    solve(root,root,isthere);
    return isthere;
}