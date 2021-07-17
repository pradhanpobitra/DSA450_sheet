#include<bits/stdc++.h>
using namespace std;

struct node {
    int mx;
    int slen;
    int elen;
    node(int x,int y,int z) {
        mx = slen = elen = x;
    }
};

void buildtree(vector<node>& segment_tree,string& s,int node,int low,int high) {

    if(low == high) {
        if(s[low] == '0') segment_tree[node].mx = segment_tree[node].slen = segment_tree[node].elen = 1;
        else segment_tree[node].mx = segment_tree[node].slen = segment_tree[node].elen = 0;
        return;
    }

    int mid = (low + high) / 2;
    buildtree(segment_tree,s,2*node+1,low,mid);
    buildtree(segment_tree,s,2*node+2,mid+1,high);
    
    segment_tree[node].mx = max(segment_tree[2*node+1].mx,segment_tree[2*node+2].mx);
    if(segment_tree[2*node+1].elen && segment_tree[2*node+2].slen) {
        segment_tree[node].mx = max(segment_tree[node].mx, segment_tree[2*node+1].elen + segment_tree[2*node+2].slen);
    }
    
    if(segment_tree[2*node+2].elen == high - mid) segment_tree[node].elen = high - mid + segment_tree[2*node+1].elen;
    else segment_tree[node].elen = segment_tree[2*node+2].elen;

    if(segment_tree[2*node+1].slen == mid + 1 - low) segment_tree[node].slen = segment_tree[2*node+2].slen + mid + 1- low;
    else segment_tree[node].slen = segment_tree[2*node+1].slen;

}

void query(vector<node>& segment_tree,int node,int l,int r,int low,int high,int& elen,int &mx) {
    if(low >= l && high <= r) {
        mx = max(mx, segment_tree[node].mx);
        mx = max(mx , elen + segment_tree[node].slen);
        if(segment_tree[node].elen == high - low + 1) {
            elen = elen + high - low + 1;
            mx = max(mx , elen);
        }
        else elen = segment_tree[node].elen;
        return;
    }
    else if(low > r || high < l) return;
    int mid = (low + high) / 2;
    query(segment_tree,2*node+1,l,r,low,mid,elen,mx);
    query(segment_tree,2*node+2,l,r,mid+1,high,elen,mx);
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<node> segment_tree(4*n, node(0,0,0));

    buildtree(segment_tree,s,0,0,n-1);
    
    int q,l,r;
    
    cin >> q;
    while(q--) {
        cin >> l >> r;
        int elen = 0, mx = 0;
        query(segment_tree,0,l,r,0,n-1,elen,mx);
        cout << mx << endl;
    }
}