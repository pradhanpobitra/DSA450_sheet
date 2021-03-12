#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int parent,vector<int> edges[],bool vis[],bool &isloop) {
    vis[i] = true;
    for(int x : edges[i]) {
        if(x == parent) continue;
        if(vis[x]) isloop = true;
        else dfs(x,i,edges,vis,isloop);
    }
}
int main() {
    int n,e,u,v;
    cin >> n >> e;
    vector<int> edges[n+1];
    while(e--) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    bool vis[n+1] = {0};
    bool isloop = false;
    dfs(1,-1,edges,vis,isloop);
    isloop == true ? cout << 0 << endl : cout << 1 << endl;
}