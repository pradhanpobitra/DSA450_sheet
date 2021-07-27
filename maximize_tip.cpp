#include<bits/stdc++.h>
using namespace std;

int solve(int A[],int B[],int n,int x,int y,vector<vector<int>> &dp,int remx) {
    if(n < 0) return 0;
    if(dp[n][remx] != -1) return dp[n][remx];
    int xtaken = x - remx;
    int ytaken = n - xtaken;
    if(xtaken < x && ytaken < y) return dp[n][remx] = max(A[n] + solve(A,B,n-1,x,y,dp,remx-1), B[n] + solve(A,B,n-1,x,y,dp,remx));
    else if(xtaken < x) return dp[n][remx] = A[n] + solve(A,B,n-1,x,y,dp,remx-1);
    else if(ytaken < y) return dp[n][remx] = B[n] + solve(A,B,n-1,x,y,dp,remx);
}

int main() {
    int n,i;
    cin >> n;
    int A[n],B[n];
    int x,y;
    cin >> x >> y;
    for(i=0;i<n;i++) cin >> A[i];
    for(i=0;i<n;i++) cin >> B[i];
    vector<vector<int>> dp(n , vector<int> (x+1, -1));
    cout << solve(A,B,n-1,x,y,dp,x);
}