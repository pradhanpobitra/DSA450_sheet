#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++) cin >> a[i];
    int mnsum = a[0] , currsum = a[0] , mxprefix = a[0];
    for(i=1;i<n;i++) {
        currsum += a[i];
        mnsum = min(mnsum , min(currsum , currsum - mxprefix));
        mxprefix = max(mxprefix , currsum);
    }
    cout << mnsum << endl;
}