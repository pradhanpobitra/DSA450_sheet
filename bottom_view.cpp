vector<int> bottomView(Node *root)
{
   // Your Code Here
   vector<int> ans;
   int low = 0, high = -1;
   unordered_map<int,Node*> h;
   queue<pair<Node*,int>> q;
   q.push(make_pair(root,0));
   while(!q.empty()) {
       auto p = q.front();
       q.pop();
       low = min(low,p.second);
       high = max(high,p.second);
       h[p.second] = p.first;
       if(p.first->left) q.push(make_pair(p.first->left,p.second-1));
       if(p.first->right) q.push(make_pair(p.first->right,p.second+1));
   }
   for(int i=low;i<=high;i++) ans.push_back(h[i]->data);
   return ans;
}