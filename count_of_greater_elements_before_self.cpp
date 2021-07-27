#include<bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>>& v,int l,int mid,int r,vector<int>& counts,vector<pair<int,int>>& temp) {

    int i = l , j = mid+1;
    int k = l;
    while(i < mid+1 && j <= r) {
        if(v[i].first <= v[j].first) {
            temp[k++] = v[i++];
        }
        else {
            temp[k++] = v[j];
            counts[v[j].second] += mid+1 - i;
            j++;
        }
    }
    while(i < mid+1) temp[k++] = v[i++];
    while(j <= r) temp[k++] = v[j++];

    k = l;
    while(k <= r)  v[k++] = temp[k];
    return;
}

void mergesort(vector<pair<int,int>> &v,int l,int r,vector<int>& counts,vector<pair<int,int>> &temp) {
    if(l >= r) return;
    int mid = (l + r) / 2;
    mergesort(v,l,mid,counts,temp);
    mergesort(v,mid+1,r,counts,temp);
    merge(v,l,mid,r,counts,temp);
    return;
}

int main() {
    int n,i,x;
    cin >> n;
    vector<pair<int,int>> v,temp;
    for(i=0;i<n;i++) {
        cin >> x;
        v.push_back(make_pair(x,i));
        temp.push_back(make_pair(x,i));
    }
    vector<int> counts(n , 0);
    mergesort(v,0, n-1, counts,temp);
    for(int x : counts) cout << x << " ";
}