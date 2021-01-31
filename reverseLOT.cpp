#include <bits/stdc++.h>
using namespace std;

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    if (root == 0)
        return ans;
    vector<pair<int, int>> v;
    queue<Node *> q;
    q.push(root);
    int level = 1;
    while (!q.empty())
    {
        int curr_level_counts = q.size();
        while (curr_level_counts--)
        {
            Node *t = q.front();
            q.pop();
            v.push_back(make_pair(t->data, level));
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        level++;
    }
    int n = v.size();
    int i = n - 1;
    level = v[n - 1].second;
    while(level)
    {
        while (i >= 0 && v[i].second == level)
            i--;
        int j = i + 1;
        while (j < n && v[j].second == level)
            ans.push_back(v[j++].first);
        level--;
    }
    return ans;
}