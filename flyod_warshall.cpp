#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 10000000
int main()
{
    //code
    int t, v, i, j;
    cin >> t;
    while (t--)
    {
        cin >> v;
        int g[v][v];
        for (i = 0; i < v; i++)
            for (j = 0; j < v; j++)
                cin >> g[i][j];
        for (int k = 0; k < v; k++)
        {
            for (i = 0; i < v; i++)
            {
                for (j = 0; j < v; j++)
                {
                    if (g[i][k] == INT_MAX || g[k][j] == INT_MAX || INT_MAX - g[i][k] < g[k][j])
                        continue;
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (g[i][j] == INT_MAX)
                    cout << "INF"
                         << " ";
                else
                    cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
}