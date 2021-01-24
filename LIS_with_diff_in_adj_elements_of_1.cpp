#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
        int mx = 1;
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (abs(a[i] - a[j]) == 1)
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};