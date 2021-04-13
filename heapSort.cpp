#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int parent,int size) {
    int lchild = 2 * parent +1;
    int rchild = lchild + 1;
    int mx;
    while(lchild < size) {
        if(rchild >= size) {
            if(a[parent] < a[lchild]) swap(a[parent],a[lchild]);
            break;
        }
        a[lchild] > a[rchild] ? mx = a[lchild] : mx = a[rchild];
        if(a[parent] >= mx) break;
        if(mx == a[lchild]) {
            swap(a[parent],a[lchild]);
            parent = lchild;
        }
        else {
            swap(a[parent],a[rchild]);
            parent = rchild;
        }
        lchild = 2 * parent +1;
        rchild = lchild + 1;
    }
}

void buildMaxHeap(int a[],int m) {
    if(m==1) return;
    int n = m -1;
    if(n % 2) {
        n--;
        n /= 2;
    }
    else {
        n -= 2;
        n /= 2;
    }
    for( ;n>=0 ; n--) {
        heapify(a,n,m);
    }
}

int main() {
    int n,i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++) cin >> a[i];
    int sizeOfheap = n;
    buildMaxHeap(a,n);
    while(sizeOfheap > 1) {
        swap(a[0],a[sizeOfheap-1]);
        sizeOfheap--;
        heapify(a,0,sizeOfheap);
    }
    for(i=0;i<n;i++) cout << a[i] << " ";
}