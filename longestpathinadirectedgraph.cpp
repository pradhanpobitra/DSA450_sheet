#include<bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,int>> edges[],int i,bool vis[],stack<int> &s) {
    vis[i]=1;
    for(auto x : edges[i]) {
        if(!vis[x.first]) dfs(edges,x.first,vis,s);
    }
    s.push(i);
}
vector<int> topoSort(vector<pair<int,int>> edges[],int V) {
    bool vis[V+1] = {0};
    stack<int> s;
    for(int i=1;i<=V;i++) {
        if(!vis[i]) dfs(edges,i,vis,s);
    }
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main() {
    int u,v,V,e,i,s,w;
    cin >> V >> e;
    vector<pair<int,int>> edges[V+1];
    cin >> s;
    int dis[V+1];
    for(i=1;i<=V;i++) dis[i] = INT_MIN;
    dis[s] = 0;
    while(e--) {
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v,w));
    }
    vector<int> sorted = topoSort(edges,V);
    for(int x : sorted) {
        if(dis[x] == INT_MIN)  continue;
        for(auto y : edges[x]) {
            if(dis[y.first] < dis[x] + y.second) dis[y.first] = dis[x] + y.second;
        }
    }
    for(i=1;i<=V;i++) cout << dis[i] << " ";
} 