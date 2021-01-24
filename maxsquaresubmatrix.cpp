#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        // code here
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    mx = max(mx, mat[i][j]);
                    continue;
                }
                if (mat[i][j] == 0)
                    continue;
                mat[i][j] = 1 + min(mat[i - 1][j - 1], min(mat[i][j - 1], mat[i - 1][j]));
                mx = max(mx, mat[i][j]);
            }
        }
        return mx;
    }
};