#include<bits/stdc++.h>
using namespace std;

void heapify(int parent,int a[],int n) {
    int lchild = 2 * parent + 1;
    int rchild = lchild + 1;
    int mx;
    while(lchild < n) {
        if(rchild >= n) {
            if(a[parent] < a[lchild]) swap(a[parent],a[lchild]);
            return;
        }
        a[lchild] > a[rchild] ? mx = a[lchild] : mx = a[rchild];
        if(a[parent] >= mx) return;
        if(mx == a[lchild]) {
            swap(a[parent],a[lchild]);
            parent = lchild;
        }
        else {
            swap(a[parent],a[rchild]);
            parent = rchild;
        }
        lchild = 2 * parent +1;
        rchild = lchild+1;
    }
}

void levelOrder(int a[],int m) {
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            int x = q.front();
            q.pop();
            cout << a[x] << " ";
            if(2*x+1 < m) q.push(2*x+1);
            if(2*x+2 < m) q.push(2*x+2); 
        }
        cout << endl;
    }
}

int main() {
    int n,i;
    cin >> n ;
    int a[n];
    for(i=0;i<n;i++) cin >> a[i];
    if(n==1) {
        cout << a[0] << endl;
        return 0;
    }
    else {
        int last = n - 1;
        if(last % 2) {
            last--;
        }
        else last -= 2;
        last /= 2;
        for(;last>=0;last--) heapify(last,a,n);
    }
    levelOrder(a,n);
    return 0;
}