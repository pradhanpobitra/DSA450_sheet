#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        // code here
        int arr[n+1];
        int dp[k+1][n+1] , i , j;
        for(i=1;i<=n;i++) arr[i] = A[i-1];
        arr[0] = 0;
        for(i=0;i<=k;i++) {
            int mx = INT_MIN;
            for(j=0;j<=n;j++) {
                if(i==0 || j<=1) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i][j-1];
                    mx = max(mx , dp[i-1][j-2] - arr[j-1]);
                    dp[i][j] = max(dp[i][j] , arr[j] + mx);
                }
            }
        }
        return dp[k][n];
    }
};