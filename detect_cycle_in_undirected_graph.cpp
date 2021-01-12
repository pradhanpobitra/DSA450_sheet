#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<int> edges[], int src, bool vis[], bool &ispresent, int parent)
    {
        vis[src] = 1;
        for (int x : edges[src])
        {
            if (x == parent)
                continue;
            if (vis[x])
                ispresent = true;
            else
                dfs(edges, x, vis, ispresent, src);
        }
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        bool vis[V] = {0};
        bool ispresent = false;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(adj, i, vis, ispresent, -1);
        }
        return ispresent;
    }
};