#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> edges[],int src,int color[],bool &ispresent) {
    if(color[src] == 2) return;
    if(color[src] == 1) {
        ispresent = true;
        return;
    }
    color[src] = 1;
    for(int x : edges[src]) dfs(edges,x,color,ispresent);
    color[src] = 2;
}
bool iscyclepresent(vector<int> edges[],int V) {
    int color[V] = {0};
    bool ispresent = false;
    for(int i=0;i<V;i++) {
        if(color[i]==0) dfs(edges,i,color,ispresent);
    }
    return ispresent;
}

int main() {
    int v,e,i,j;
    cin >> v >> e;
    vector<int> edges[v];
    while(e--) {
        cin >> i >> j;
        edges[i].push_back(j);
    }
    bool ans = iscyclepresent(edges,v);
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}