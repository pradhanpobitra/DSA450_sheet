#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int arr[],int low,int high) {
    if(low==high) return 0;
    if(dp[low][high]!=-1) return dp[low][high];
    int ans = INT_MAX;
    for(int k=low;k<high;k++) {
        ans = min(ans,arr[low-1]*arr[k]*arr[high] + solve(arr,low,k) + solve(arr,k+1,high));
    }
    return dp[low][high] = ans;
}
int main() {
    int n,i;
    cin >> n;
    int arr[n];
    memset(dp,-1,sizeof dp);
    for(i=0;i<n;i++) cin >> arr[i];
    cout << solve(arr,1,n-1);
}