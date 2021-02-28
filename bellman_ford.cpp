#include<bits/stdc++.h>
using namespace std;

bool detectNegCycle(vector<pair<pair<int,int>,int>> &edges,int V) {
    int dis[V];
    for(int i=0;i<V;i++) dis[i] = INT_MAX;
    dis[0] = 0;
    for(int i=1;i<V;i++) {
        for(auto edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if(dis[u] == INT_MAX || dis[v] - dis[u] <= w) continue;
            dis[v] = dis[u] + w;
        }
    }
    for(auto edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if(dis[u] == INT_MAX || dis[v] - dis[u] <= w) continue;
            dis[v] = dis[u] + w;
            return true;
    }
    return false;
}

int main() {
    int u,v,w,e,i,V;
    vector<pair<pair<int,int>,int>> edges;
    cin >> V >> e;
    while(e--) {
        cin >> u >> v >> w;
        edges.push_back(make_pair(make_pair(u,v),w));
    }
    cout << detectNegCycle(edges,V) << endl;
}