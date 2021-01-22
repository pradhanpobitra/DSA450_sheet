#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = INT_MIN;
    if (n >= x)
        ans = max(ans, 1 + solve(n - x, x, y, z));
    if (n >= y)
        ans = max(ans, 1 + solve(n - y, x, y, z));
    if (n >= z)
        ans = max(ans, 1 + solve(n - z, x, y, z));
    return dp[n] = ans;
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    memset(dp, -1, sizeof dp);
    int ans = solve(n, x, y, z);
    if (ans < 0)
        return 0;
    return ans;
}