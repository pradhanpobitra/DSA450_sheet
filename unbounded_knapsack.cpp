#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[1001][1001];
    int solve(int val[],int wt[],int w,int i) {
        if(i<0) return 0;
        if(dp[w][i]!=-1) return dp[w][i];
        if(wt[i] <= w) return dp[w][i]=max(val[i] + solve(val,wt,w-wt[i],i),solve(val,wt,w,i-1));
        else return dp[w][i]=solve(val,wt,w,i-1);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof dp);
        return solve(val,wt,W,N-1);
    }
};