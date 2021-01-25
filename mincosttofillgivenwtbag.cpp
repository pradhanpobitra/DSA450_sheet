#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
#define M 100000001
class Solution
{
public:
    long long dp[1001][1001];
    long long solve(int cost[], int i, int W)
    {
        if (W == 0)
            return 0;
        if (i == -1)
            return M;
        if (dp[i][W] != -1)
            return dp[i][W];
        if (cost[i] == -1)
            return dp[i][W] = solve(cost, i - 1, W);
        if (i + 1 > W)
            return dp[i][W] = solve(cost, i - 1, W);
        return dp[i][W] = min((long long)cost[i] + solve(cost, i, W - i - 1), solve(cost, i - 1, W));
    }
    int minimumCost(int cost[], int N, int W)
    {
        // Your code goes here
        memset(dp, -1, sizeof dp);
        long long ans = solve(cost, N - 1, W);
        if (ans >= M)
            return -1;
        return ans;
    }
};