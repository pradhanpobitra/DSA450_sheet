#include<bits/stdc++.h>
using namespace std;

int solve(int keys[],int freq[],int l,int r,int **dp) {
    if(l > r) return 0;
    if(l==r) return freq[l];
    if(dp[l][r]!=-1) return dp[l][r];
    int ans = 0;
    int mn = INT_MAX;
    for(int i=l;i<=r;i++) ans += freq[i];
    for(int k=l;k<=r;k++) {
        mn = min(mn , solve(keys,freq,l,k-1,dp) + solve(keys,freq,k+1,r,dp));
    }
    return dp[l][r] = ans + mn;
}

int main() {
    int n,i;
    cin >> n;
    int keys[n],freq[n];
    for(i=0;i<n;i++) cin >> keys[i];
    for(i=0;i<n;i++) cin >> freq[i];
    int **dp = new int*[n];
    for(i=0;i<n;i++) dp[i] = new int[n];
    for(i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = -1;
    cout << solve(keys,freq,0,n-1,dp) << endl;
}