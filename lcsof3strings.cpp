#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int lcs3(string &a, string &b, string &c, int i, int j, int k)
{
    if (i < 0 || j < 0 || k < 0)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    if (a[i] == b[j] && a[i] == c[k])
        return dp[i][j][k] = 1 + lcs3(a, b, c, i - 1, j - 1, k - 1);
    if (a[i] == b[j])
        return dp[i][j][k] = max(lcs3(a, b, c, i - 1, j - 1, k), lcs3(a, b, c, i, j, k - 1));
    if (a[i] == c[k])
        return dp[i][j][k] = max(lcs3(a, b, c, i - 1, j, k - 1), lcs3(a, b, c, i, j - 1, k));
    if (b[j] == c[k])
        return dp[i][j][k] = max(lcs3(a, b, c, i, j - 1, k - 1), lcs3(a, b, c, i - 1, j, k));
    return dp[i][j][k] = max(lcs3(a, b, c, i, j - 1, k - 1), max(lcs3(a, b, c, i - 1, j, k - 1), lcs3(a, b, c, i - 1, j - 1, k)));
}
int main()
{
    //code
    int t, i, j, k;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> i >> j >> k;
        cin >> a >> b >> c;
        memset(dp, -1, sizeof dp);
        cout << lcs3(a, b, c, i - 1, j - 1, k - 1) << endl;
    }
}