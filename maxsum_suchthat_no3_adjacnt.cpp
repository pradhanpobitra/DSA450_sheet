#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i;
    cin >> n;
    int a[n] , dp[n];
    for(i=0;i<n;i++) cin >> a[i];
    int mx = a[0];
    dp[0]=a[0];
    dp[1] = dp[0]+a[1];
    mx = dp[1];
    dp[2] = max(a[2] + a[1] , a[2] + a[0]);
    mx = max(mx,dp[2]);
    for(i=3;i<n;i++) {
        dp[i] = max(a[i] + a[i-1] + dp[i-3],a[i] + dp[i-2]);
        mx = max(mx,dp[i]);
    }
    cout << mx << endl;
}