#include<bits/stdc++.h>
using namespace std;

int get_parent(int i,int par[]) {
    if(par[i]==-1) return i;
    return par[i] = get_parent(par[i],par);
}

bool can_include(pair< pair<int,int> , int> &edge, int par[]) {
    int u = edge.first.first;
    int v = edge.first.second;
    int pu = get_parent(u,par);
    int pv = get_parent(v,par);
    if(pu == -1 && pv==-1) return true;
    if(pu == pv) return false;
    return true;
}

void include_edge(pair< pair<int,int> , int> edge,int par[],int rank[]) {
    int u = edge.first.first;
    int v = edge.first.second;
    int pu = get_parent(u,par);
    int pv = get_parent(v,par);
    if(rank[pu]==rank[pv]) {
        rank[pu]++;
        par[pv] = pu;
    }
    else if(rank[pu] > rank[pv]) {
        par[pv] = pu;
    }
    else par[pu] = pv;
}

bool myway(const pair< pair<int,int> , int> &a,const pair< pair<int,int> , int> &b) {
    return a.second < b.second;
}
int main() {
    int v,e,w,i,j;
    cin >> v >> e;
    int par[v+1],rank[v+1];
    for(i=0;i<=v;i++) par[i]=-1 , rank[i]=1;
    vector< pair< pair<int,int> , int> > edges;
    while(e--) {
        cin >> i >> j >> w;
        edges.push_back(make_pair( make_pair(i,j) , w ));
    }
    sort(edges.begin() , edges.end() , myway);
    int c = 0;
    int sum = 0;
    vector< pair<int,int> > ans;
    for(auto edge : edges) {
        if(c == v-1) break;
        if(!can_include(edge,par)) continue;
        c++;
        include_edge(edge,par,rank);
        sum += edge.second;
        ans.push_back(edge.first);
    }
    cout << sum << endl;
    for(auto x : ans) cout << x.first << "-->" << x.second << endl;
}
