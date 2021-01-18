#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
// Function to construct and print MST for
// a graph represented using adjacency
// list representation, with V vertices.
#define pii pair<int, int>
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        bool vis[V];
        int mnwt[V], sum = 0, i;
        for (i = 0; i < V; i++)
            vis[i] = 0, mnwt[i] = INT_MAX;
        mnwt[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, 0));
        int c = -1;
        while (!pq.empty() && c < V - 1)
        {
            pii x = pq.top();
            pq.pop();
            if (vis[x.second])
                continue;
            vis[x.second] = 1;
            c++;
            sum += x.first;
            for (auto y : adj[x.second])
            {
                if (vis[y[0]])
                    continue;
                if (y[1] >= mnwt[y[0]])
                    continue;
                mnwt[y[0]] = y[1];
                pq.push(make_pair(y[1], y[0]));
            }
        }
        return sum;
    }
};