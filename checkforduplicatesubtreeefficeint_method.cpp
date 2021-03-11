string solve(Node *root,map<string,bool> &h,bool &ispresent) {
    if(root==0) return "";
    if(!root->left && !root->right) {
        string t;
        t.push_back('(');
        t.push_back(root->data);
        t.push_back(')');
        return t;
    }
    string temp1 = solve(root->left,h,ispresent);
    string temp2 = solve(root->right,h,ispresent);
    string t;
    t.append("(" + root->data);
    t.append(temp1 + temp2);
    t.push_back(')');
    if(h[t]) ispresent = true;
    h[t] = true;
    return t;
}
bool dupSub(Node *root)
{
     //your code here
     map<string,bool> h;
     bool ispresent = false;
     solve(root,h,ispresent);
     return ispresent;
}