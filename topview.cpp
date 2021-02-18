vector<int> topView(struct Node *root)
{
    //Your code here
    vector<int> ans;
    unordered_map<int,Node*> h;
    int low=0,high=-1;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    
    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        if(h[t.second]==0) {
            h[t.second] = t.first;
            low = min(low,t.second);
            high = max(high,t.second);
        }
        if(t.first->left)  q.push(make_pair(t.first->left,t.second-1));
        if(t.first->right) q.push(make_pair(t.first->right,t.second+1));
    }
    for(int i=low;i<=high;i++) ans.push_back(h[i]->data);
    return ans;
}