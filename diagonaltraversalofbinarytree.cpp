vector<int> diagonal(Node *root)
{
   // your code here
   queue<Node*> curr,next;
   vector<int> ans;
   curr.push(root);
   Node *t;
   while(!curr.empty() || !next.empty()) {
       while(!curr.empty()) {
           t = curr.front();
           curr.pop();
           while(t) {
               ans.push_back(t->data);
               if(t->left) next.push(t->left);
               t = t->right;
           }
       }
       swap(next,curr);
   }
   return ans;
}