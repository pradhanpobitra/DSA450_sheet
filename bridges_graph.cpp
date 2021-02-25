#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > bridges;
int dfs(int i,int parent,vector<int> edges[],bool vis[],int dis[],int low[],int &d) {
    vis[i] = true;
    dis[i] = d++;
    low[i] = dis[i];
    for(int x : edges[i]) {
        if(x != parent) {
            if(vis[x]) low[i] = min(low[i],dis[x]);
            else low[i] = min(low[i],dfs(x,i,edges,vis,dis,low,d));
            if(low[x] > dis[i]) bridges.push_back(make_pair(i,x));
        }
    }
    return low[i];
}
int main() {
    int v,e,i,j;
    cin >> v >> e;
    vector<int> edges[v+1];
    while(e--) {
        cin >> i >> j;
        edges[i].push_back(j);
        edges[j].push_back(i);
    }
    int dis[v+1] , low[v+1];
    bool vis[v+1] = {0};
    int d = 1;
    dfs(1,-1,edges,vis,dis,low,d);
    if(bridges.size()==0) cout << "no bridges" << endl;
    else {
        bool is[v+1] = {0};
        for(pair<int,int> x : bridges) {
            cout << x.first << " " << x.second << " ";
        }
    }
}