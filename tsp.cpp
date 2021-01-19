#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > adj;

int tsp(int i,int mask,int v,vector<vector<int> > &dp) {
    mask = mask | (1 << i);
    if(mask==(1 << v) - 1) return adj[i][0];
    if(dp[mask][i]!=-1) return dp[mask][i];
    int ans = INT_MAX;
    for(int j=0;j < v; j++) {
        if(i==j) continue;
        if((mask & (1 << j)) == 0) ans = min(ans, adj[i][j] + tsp(j,mask,v,dp));
    }
    dp[mask][i] = ans;
    mask = mask ^ (1 << i);
    return ans;
}

int main() {
    int v,i,j;
    cin >> v;
    int x;
    for(i=1;i<=v;i++) {
        vector<int> temp;
        for(j=1;j<=v;j++) {
            cin >> x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }
    vector<vector<int> > dp;
    int rows = 1 << v;
    int cols = v;
    for(i=0;i<rows;i++) {
        vector<int> t;
        for(j=0;j<cols;j++) t.push_back(-1);
        dp.push_back(t);
    }
    cout << tsp(0,0,v,dp) << endl;
}