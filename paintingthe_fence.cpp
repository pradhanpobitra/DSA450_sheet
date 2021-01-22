#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

long long dp[100001];
class Solution
{
public:
    long long solve(int n, int k)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return k;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = (k % M * (solve(n - 2, k) % M + solve(n - 1, k) % M) % M) % M;
    }
    long long countWays(int n, int k)
    {
        // code here
        if (n == 1)
            return k;
        if (k == 1)
        {
            if (n == 2)
                return 1;
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        long long ans = (k % M * solve(n - 2, k - 1) % M) % M;
        ans = (ans % M + (k % M * solve(n - 1, k - 1) % M) % M) % M;
        return ans;
    }
};