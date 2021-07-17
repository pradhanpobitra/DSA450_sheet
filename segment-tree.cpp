#include<bits/stdc++.h>
using namespace std;

int buildsegmenttree(vector<int> &segmenttree,vector<int> &arr,int node,int l,int r) {
    if(l > r) return INT_MIN;
    if(l==r) return segmenttree[node] = arr[l];
    int mid = (l+r) / 2;
    return segmenttree[node] = buildsegmenttree(segmenttree,arr,2*node + 1,l,mid) + buildsegmenttree(segmenttree,arr,2*node + 2,mid+1,r);
}

int query(vector<int> &segment_tree,vector<int>& lazy_tree,int node,int l,int r,int low,int high) {
    if(lazy_tree[node]) {
        segment_tree[node] += lazy_tree[node] * (high - low + 1);
    }
    if(low != high) {
        lazy_tree[2*node+1] += lazy_tree[node];
        lazy_tree[2*node+2] += lazy_tree[node];
    }
    lazy_tree[node] = 0;

    if(low >= l && high <= r) return segment_tree[node];
    else if(low > r || high < l) return 0;
    int mid = (low + high) / 2;
    return query(segment_tree,lazy_tree,2*node+1,l,r,low,mid) + query(segment_tree,lazy_tree,2*node+2,l,r,mid+1,high);
}

void lazy_update(vector<int> &segment_tree,vector<int>& lazy_tree,int node,int l,int r,int x,int low,int high) {
    if(lazy_tree[node]) {
        segment_tree[node] += lazy_tree[node] * (high - low + 1);
    }
    if(low == high) { lazy_tree[node] = 0; return; }
    lazy_tree[2*node+1] += lazy_tree[node];
    lazy_tree[2*node+2] += lazy_tree[node];
    lazy_tree[node] = 0;

    if(low >= l && high <= r) {
        lazy_tree[2*node+1] += x;
        lazy_tree[2*node+2] += x;

        segment_tree[node] += x * (high - low + 1);
        return;
    }
    else if(low > r || high < l) return;
    int mid = (low + high) / 2;
    lazy_update(segment_tree,lazy_tree,2*node+1,l,r,x,low,mid);
    lazy_update(segment_tree,lazy_tree,2*node+2,l,r,x,mid+1,high);

    segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
    return;
}


int main() {
    int n,x;
    cin >> n;
    
    vector<int> arr,segment_tree(4*n + 5, INT_MIN),lazy_tree(4*n+5,0);
    
    for(int i=0;i<n;i++) {
        cin >> x;
        arr.push_back(x);
    }
    buildsegmenttree(segment_tree,arr,0,0,n-1);

    int u,q,l,r;
    cin >> q;
    while(q--) {
        cin >> u;
        cin >> l >> r;
        if(u==2) cout << query(segment_tree,lazy_tree,0,l,r,0,n-1) << endl;
        else {
            int x;
            cin >> x;
            lazy_update(segment_tree,lazy_tree,0,l,r,x,0,n-1);
        } 
    }
}