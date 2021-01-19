#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bellmanFord(vector<vector<int>> &edges, int mnwt[], int n)
    {
        int i = 0;
        while (i < n - 1)
        {
            for (auto x : edges)
            {
                if (mnwt[x[0]] == INT_MAX)
                    continue;
                if (mnwt[x[1]] > mnwt[x[0]] + x[2])
                    mnwt[x[1]] = mnwt[x[0]] + x[2];
            }
            i++;
        }
    }
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // Code here
        int mnwt[n];
        int i;
        for (i = 0; i < n; i++)
            mnwt[i] = INT_MAX;
        mnwt[0] = 0;
        bellmanFord(edges, mnwt, n);
        bool isthere = false;
        for (auto x : edges)
        {
            if (mnwt[x[1]] > mnwt[x[0]] + x[2])
                isthere = true;
        }
        return isthere;
    }
};