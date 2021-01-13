#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int src, bool vis[], vector<int> edges[])
    {
        vis[src] = 1;
        for (int x : edges[src])
        {
            if (!vis[x])
                dfs(x, vis, edges);
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int availEdges = connections.size();
        if (availEdges < n - 1)
            return -1;
        int noCC = 0;
        vector<int> edges[n];
        for (vector<int> x : connections)
        {
            edges[x[0]].push_back(x[1]);
            edges[x[1]].push_back(x[0]);
        }
        bool vis[n];
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                noCC++;
                dfs(i, vis, edges);
            }
        }
        return noCC - 1;
    }
};