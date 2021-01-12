#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == 0)
            return nullptr;
        Node *head = new Node(1);
        queue<Node *> q;
        q.push(node);
        unordered_map<Node *, bool> h;
        unordered_map<Node *, Node *> corres;
        h[node] = true;
        corres[node] = head;
        while (!q.empty())
        {
            Node *t = q.front();
            q.pop();
            for (Node *x : t->neighbors)
            {
                if (h[x])
                {
                    (corres[t]->neighbors).push_back(corres[x]);
                    continue;
                }
                Node *p = new Node(x->val);
                h[x] = true;
                corres[x] = p;
                (corres[t]->neighbors).push_back(p);
                q.push(x);
            }
        }
        return head;
    }
};