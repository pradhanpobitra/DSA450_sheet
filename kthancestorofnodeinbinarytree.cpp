#include<bits/stdc++.h>
using namespace std;
void dfs(int x,int parent,vector< vector<int> > &dp,vector<int> edges[]) {
    dp[x][0] = parent;
    for(int i=1;i < 32;i++) {
        int y = dp[x][i-1];
        if(y!=-1) dp[x][i] = dp[y][i-1];
    }
    for(int y : edges[x]) dfs(y,x,dp,edges);
}
int main() {
    int v,e,u,n;
    cin >> n >> e;
    vector<int> edges[n+1];
    while(e--) {
        cin >> u >> v;
        edges[u].push_back(v);
    }
    vector< vector<int> > dp(n+1, vector<int> (32, -1));
    for(int x : edges[1]) dfs(x,1,dp,edges);
    // for(int i=1; i<= n ; i++) {
    //     for(int j = 0; j < 32 ;j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    int q,k;
    cin >> q;
    while(q--) {
        cin >> u >> k;
        int ans = -1;
        for(int i = 31; i>=0 && u != -1; i--) {
            if(k & (1 << i)) {
                ans = dp[u][i];
                u = ans;
                k = k ^ (1 << i);
            } 
        }
        cout << ans << endl;
    }
}