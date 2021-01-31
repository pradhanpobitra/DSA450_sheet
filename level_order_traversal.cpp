#include <bits/stdc++.h>
using namespace std;

vector<int> levelOrder(Node *node)
{
    //Your code here
    vector<int> ans;
    if (node == 0)
        return ans;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        ans.push_back(t->data);
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
    return ans;
}