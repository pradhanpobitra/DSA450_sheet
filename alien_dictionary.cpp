#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> edges[], int i, stack<int> &st, bool vis[])
    {
        if (vis[i])
            return;
        vis[i] = true;
        for (int x : edges[i])
        {
            dfs(edges, x, st, vis);
        }
        st.push(i);
    }
    int differing(string &back, string &front)
    {
        int i = 0;
        while (back[i] != '\0' && front[i] != '\0')
        {
            if (back[i] != front[i])
                return i;
            i++;
        }
        return i;
    }
    string findOrder(string dict[], int N, int K)
    {
        //code here
        vector<int> edges[K];
        int i = 0;
        string back, front;
        while (i < N - 1)
        {
            back = dict[i];
            front = dict[i + 1];
            int j = differing(back, front);
            if (back[j] == '\0' || front[j] == '\0')
            {
                i++;
                continue;
            }
            edges[back[j] - 'a'].push_back(front[j] - 'a');
            i++;
        }
        bool vis[K] = {0};
        stack<int> st;
        for (i = 0; i < K; i++)
        {
            if (vis[i] == 0)
                dfs(edges, i, st, vis);
        }
        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top() + 'a');
            st.pop();
        }
        return ans;
    }
};