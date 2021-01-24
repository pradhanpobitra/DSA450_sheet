#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        int m = matrix[0].size();
        vector<vector<int>> dp(N, vector<int>(m, 0));
        for (int col = 0; col < m; col++)
            dp[0][col] = matrix[0][col];
        for (int row = 1; row < N; row++)
        {
            dp[row][0] = matrix[row][0] + max(dp[row - 1][0], dp[row - 1][1]);
            dp[row][m - 1] = matrix[row][m - 1] + max(dp[row - 1][m - 1], dp[row - 1][m - 2]);
            for (int col = 1; col < m - 1; col++)
                dp[row][col] = matrix[row][col] + max(dp[row - 1][col], max(dp[row - 1][col - 1], dp[row - 1][col + 1]));
        }
        int mx = 0;
        for (int col = 0; col < m; col++)
            mx = max(mx, dp[N - 1][col]);
        return mx;
    }
};