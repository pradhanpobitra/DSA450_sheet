#include<bits/stdc++.h>
using namespace std;

// 1.topological sort algorithm works only and ONLY for DAGs ==> directed acyclic graphs.
void dfs(vector<int> edges[],int src,bool vis[],stack<int> &st) {
    vis[src] = 1;
    for(int x : edges[src]) {
        if(!vis[x]) dfs(edges,x,vis,st);
    } 
    st.push(src);
}

vector<int> topoSort(vector<int> edges[],int V) {
    vector<int> ans;
    stack<int> st;
    bool vis[V] = {0};
    for(int i=0;i<V;i++) {
        if(!vis[i]) dfs(edges,i,vis,st);
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


int main() {
    int v,e,i,j;
    cin >> v >> e;
    vector<int> edges[v];
    while(e--) {
        cin >> i >> j;
        edges[i].push_back(j);
    }
    vector<int> ans = topoSort(edges,v);
    for(int x : ans) cout << x << " ";
    cout << endl;
}