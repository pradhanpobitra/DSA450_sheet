#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  long long dp[1001][1001];
    long long solve(int s[],int i,int n) {
        if(n==0) return 1;
        if(i < 0){
            if(n>0) return 0;
            return 1;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        if(s[i] > n) return dp[i][n]=solve(s,i-1,n);
        return dp[i][n]=solve(s,i-1,n) + solve(s,i,n-s[i]);
    }
    long long int count( int S[], int m, int n )
    {
       
        //code here.
        memset(dp,-1,sizeof dp);
        long long ans = solve(S,m-1,n);
        return ans;
    }
};