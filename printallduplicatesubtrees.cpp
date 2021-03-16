string postorder(Node *root,set<int> &s,map<string,int> &h) {
    if(root==0) return "";
    string st;
    st.push_back('(');
    string num;
    int x = root->data;
    while(x) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(),num.end());
    st.append(num);
    string l = postorder(root->left,s,h);
    string r = postorder(root->right,s,h);
    st.append(l);
    st.append(r);
    st.push_back(')');
    h[st]++;
    if(h[st]==2) {
        s.insert(root->data);
    }
    return st;
}
void printAllDups(Node* root)
{
    // Code here
    map<string,int> h;
    set<int> s;
    postorder(root,s,h);
    if(s.size()==0) cout << -1;
    else {
        for(int x : s) cout << x << " ";
    }
}