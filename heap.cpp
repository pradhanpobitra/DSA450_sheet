#include<iostream>
using namespace std;

void heapify(int a[],int parent,int n) {
    int lchild ;
    int rchild ;
    while(parent < n) {
        lchild = 2 * parent +1;
        rchild = 2 * parent +2;
        if(lchild >= n) return;
        if(rchild >= n) {
            if(a[parent] < a[lchild]) swap(a[parent],a[lchild]);
            return;
        }
        else {
            int mx = a[lchild] > a[rchild] ? lchild : rchild;
            if(a[parent] >= a[mx]) return;
            swap(a[parent],a[mx]);
            parent = mx;
        }
    }
}

void buildMaxheap(int a[],int n) {
    int last_child = n-1;
    int parent = (last_child - 1) / 2;

    while(parent >= 0) {
        heapify(a,parent,n);
        parent--;
    }
}

int main() {
    int i,n;
    cin >> n;
    int a[n];
    for(i=0;i < n; i++) cin >> a[i];
    buildMaxheap(a,n);
    for(i=0;i<n;i++) cout << a[i] << " ";
}