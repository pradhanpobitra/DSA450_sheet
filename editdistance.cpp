#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    int solve(string &s, string &t, int i, int j)
    {
        if (i < 0 && j < 0)
            return 0;
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = solve(s, t, i - 1, j - 1);
        return dp[i][j] = 1 + min(solve(s, t, i - 1, j), min(solve(s, t, i, j - 1), solve(s, t, i - 1, j - 1)));
    }
    int editDistance(string s, string t)
    {
        // Code here
        memset(dp, -1, sizeof dp);
        int n = s.length();
        int m = t.length();
        int ans = solve(s, t, n - 1, m - 1);
        return ans;
    }
};