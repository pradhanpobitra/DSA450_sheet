#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> edges[],int i,bool &isloop,int color[]) {
    color[i]=1;
    for(int x : edges[i]) {
        if(color[x]==1) {
            isloop = true;
            return;
        }
        else if(color[x] == 2) continue;
        else dfs(edges,x,isloop,color);
    }
    color[i] = 2;
}
int main() {
    int v,e,i,j;
    cin >> v >> e;
    vector<int> edges[v];
    vector<pair<int,int> > edge;
    while(e--) {
        cin >> i >> j;
        edge.push_back(make_pair(i,j));
    }
    for(auto x : edge) {
        edges[x.second].push_back(x.first);
    }
    int color[v] = {0};
    bool isloop = false;
    for(i=0;i<v;i++) {
        if(color[i]==0) dfs(edges,i,isloop,color);
    }
    isloop ? cout << 0 << endl : cout << 1 << endl; 
}