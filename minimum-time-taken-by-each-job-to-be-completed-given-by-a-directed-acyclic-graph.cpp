#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> edges[],int v) {
    int indegree[v+1] = {0};
    int i;
    for(i=1;i<=v;i++) {
        for(int j : edges[i]) indegree[j]++;
    }
    int mn[v+1];
    queue<int> q;
    for(i=1;i<=v;i++){
        mn[i] = INT_MAX;
        if(indegree[i]==0)  { mn[i] = 1; q.push(i); }
    } 
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int y : edges[x]) {
            if(mn[y] > mn[x] + 1) {
                mn[y] = 1 + mn[x];
                q.push(y);
            }
        }
    }
    for(i=1;i<=v;i++) cout << mn[i] << " ";
}
int main(){
    int v,e,i,j;
    cin >> v >> e;
    vector<int> edges[v+1];
    while(e--) {
        cin >> i >> j;
        edges[i].push_back(j);
    }
    solve(edges,v);
}