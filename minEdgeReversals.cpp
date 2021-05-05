#include<bits/stdc++.h>
using namespace std;

int BFS01(vector<pair<int,int>> edges[],int src,int des,int n) {
    int mindis[n];
    for(int i=0;i<n;i++) mindis[i] = INT_MAX;
    mindis[src] = 0;
    bool vis[n] = {0};
    deque<int> d;
    d.push_back(src);
    while(!d.empty()) {
        int x = d.front();
        d.pop_front();
        if(x == des) return mindis[x];
        if(vis[x]) continue;
        vis[x] = true;
        for(pair<int,int> y : edges[x]) {
            if(mindis[x] + y.second < mindis[y.first]) {
                mindis[y.first] = mindis[x] + y.second;
                if(y.second) d.push_back(y.first);
                else d.push_back(y.first);
            }
        }
    }
    return INT_MAX;
}

int main() {
    int u,v,w,n,m;
    cin >> n >> m;
    vector<pair<int,int>> edges[n];
    while(m--) {
        cin >> u >> v;
        edges[u].push_back(make_pair(v,0));
        edges[v].push_back(make_pair(u,1));
    }
    cin >> u >> v;
    cout << BFS01(edges,u,v,n);
}