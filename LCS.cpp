#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int solve(string &s1, string &s2, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1);
    return dp[i][j] = max(solve(s1, s2, i, j - 1), solve(s1, s2, i - 1, j));
}
int lcs(int x, int y, string s1, string s2)
{
    memset(dp, -1, sizeof dp);
    // your code here
    int ans = solve(s1, s2, x - 1, y - 1);
    return ans;
}