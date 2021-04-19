#include<bits/stdc++.h>
using namespace std;

bool solve(vector<pair<int,int>> edges[],int src,bool &hasLength,int k,int currLength,bool vis[]) {
    vis[src] = true;
    if(currLength >= k) {
        hasLength = true;
        return true;
    }
    for(pair<int,int> p : edges[src]) {
        if(!vis[p.first]) {
            bool trynasolve = solve(edges,p.first,hasLength,k,currLength + p.second,vis);
            if(trynasolve) return true;
        }
    }
    vis[src] = false;
    return false;
}

int main() {
    int w,n,e,k,u,v;
    cin >> n >> e >> k;
    vector<pair<int,int>> edges[n];
    while(e--) {
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v,w));
        edges[v].push_back(make_pair(u,w));
    }
    int src;
    cin >> src;
    bool hasLength = false;
    bool vis[n] = {0};
    solve(edges,src,hasLength,k,0,vis);
    if(hasLength) cout << "YES" << endl;
    else cout << "NO" << endl;
}