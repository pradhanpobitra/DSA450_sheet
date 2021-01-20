#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(int w, int wt[], int val[], int i)
{
    if (i < 0)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];
    if (wt[i] <= w)
        return dp[i][w] = max(val[i] + solve(w - wt[i], wt, val, i - 1), solve(w, wt, val, i - 1));
    return dp[i][w] = solve(w, wt, val, i - 1);
}
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    memset(dp, -1, sizeof dp);
    int ans = solve(W, wt, val, n - 1);
    return ans;
}