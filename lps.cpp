#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    int lcs(string &a, string &b, int i, int j)
    {

        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j])
            return dp[i][j] = 1 + lcs(a, b, i - 1, j - 1);
        return dp[i][j] = max(lcs(a, b, i, j - 1), lcs(a, b, i - 1, j));
    }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        memset(dp, -1, sizeof dp);
        int n = s.length();
        return lcs(s, t, n - 1, n - 1);
    }
};