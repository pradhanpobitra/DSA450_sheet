#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        int mx = 0;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0 || j==0) dp[i][j] = 0;
                else if(S1[i-1]==S2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
                mx = max(mx,dp[i][j]);
            }
        }
        return mx;
    }
};