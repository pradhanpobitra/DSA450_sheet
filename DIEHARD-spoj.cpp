#include<bits/stdc++.h>
using namespace std;

int dp[1101][1101][4];
int solve(int h,int a,int p) {
    if(h <= 0 || a <= 0) return 0;
    if(dp[h][a][p] != -1) return dp[h][a][p];
    if(p==1) return dp[h][a][p]=1 + max(solve(h-5,a-10,2),solve(h-20,a+5,3));
    else if(p==2) return dp[h][a][p]=1 + max(solve(h+3,a+2,1),solve(h-20,a+5,3));
    else return dp[h][a][p]=1 + max( solve(h+3,a+2,1) , solve(h-5,a-10,3) );
}

int main() {
    int h,a,t,ans;
    cin >> t;
    while(t--) {
        cin >> h >> a;
        memset(dp,-1,sizeof(dp));
        ans = 1 + max(solve(h+3,a+2,1),solve(h-5,a-10,2));
        ans = max(ans , 1 + solve(h-20,a+5,3));
        cout << ans-1 << endl;
    }
}