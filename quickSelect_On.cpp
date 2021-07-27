#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& v,int i,int r) {
    int pivot = v[i];
    int l = i;
    l++;
    while(l < r) {
        while(l < r && v[l] <= pivot) l++;
        while(r > l && v[r] > pivot) r--;
        if(l < r) {
            swap(v[l],v[r]);
            l++;
            r--;
        }
    }
    swap(v[i],v[r]);
    return r;
}

int quickselect(vector<int>& v,int l,int r,int index) {
    int range = (r - l + 1);
    int random_index = (rand() % range) + l;
    swap(v[l],v[random_index]);
    int j = partition(v,l,r);
    if(j == index) return v[j];
    else if(j < index) return quickselect(v,j+1,r,index);
    else return quickselect(v,l,j-1,index);
}

int main() {
    int n,x,k;
    vector<int> v;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> x;
        v.push_back(x);
    }
    cout << quickselect(v,0,n-1,k-1);
}