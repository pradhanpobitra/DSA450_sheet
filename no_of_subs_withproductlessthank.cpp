#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1001][1001];
int solve(ll a[],ll product,ll index,ll k) {
    if(index==-1) {
        if(product==0) return 0;
        return 1;
    }
    if(dp[product][index]!=-1) return dp[product][index];
    if(product==0) {
        if(a[index] >= k) return dp[product][index] = solve(a,product,index-1,k);
        return dp[product][index]=solve(a,a[index],index-1,k) + solve(a,0,index-1,k);
    }
    else {
        if(product * a[index] >= k) return dp[product][index] = solve(a,product,index-1,k);
        return dp[product][index] = solve(a,product,index-1,k) + solve(a,product*a[index],index-1,k);
    }
}
int main() {
    ll n,k,i;
    cin >> n >> k;
    ll a[n];
    for(i=0;i<n;i++) cin >> a[i];
    memset(dp,-1,sizeof dp);
    cout << solve(a,0,n-1,k) << endl;
}