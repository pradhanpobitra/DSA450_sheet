#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[501][501];
    int solve(string &s, int i, int j)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            return dp[i][j] = max(solve(s, i, j - 1), solve(s, i - 1, j));
        if (s[i] == s[j])
            return dp[i][j] = 1 + solve(s, i - 1, j - 1);
        return dp[i][j] = max(solve(s, i, j - 1), solve(s, i - 1, j));
    }
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        int n = str.length();
        memset(dp, -1, sizeof dp);
        return solve(str, n - 1, n - 1);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution ans;
    cout << ans.LongestRepeatingSubsequence(s) << endl;
}