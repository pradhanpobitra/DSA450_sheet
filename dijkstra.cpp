#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int* dijkstra(vector<pair<int,int> > edges[],int src,int V) {
    bool vis[V] = {0};
    int *mindis = new int[V];
    mindis[src] = 0;
    priority_queue< pii, vector<pii> , greater<pii> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p.second]) continue;
        vis[p.second] = 1;
        mindis[p.second] = p.first;
        for(auto x : edges[p.second]) {
            if(!vis[x.first]) {
                pq.push(make_pair(x.second + p.first, x.first));
            }
        }
    }
    return mindis;
}
int main() {
    int V,e,i,j,w;
    cin >> V >> e;
    vector< pair<int,int> > edges[V];
    while(e--) {
        cin >> i >> j >> w;
        edges[i].push_back(make_pair(j,w));
        edges[j].push_back(make_pair(i,w));
    }
    cin >> i;
    int *mindis = dijkstra(edges,i,V);
    cout << endl;
    for(i=0;i<V;i++) cout << mindis[i] << " ";
    delete mindis;
}