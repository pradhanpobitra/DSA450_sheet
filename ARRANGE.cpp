#include<bits/stdc++.h>
using namespace std;


int main() {
    int t,n,i;
    cin >> t;
    while(t--) {
        cin >> n;
        int a[n];
        for(i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        if(n == 1) {
            cout << a[0] << endl;
            continue;
        }
        if(a[n-1] == 3 && a[n-2] == 2) {
            for(i=0; i < n-2; i++) cout << 1 << " ";
            cout << 2 << " " << 3 << endl;
            continue;
        }
        int lastone = -1;
        for(i=0;i<n;i++) if(a[i] == 1) lastone = i;
        sort(a+lastone+1,a+n,greater<int>());
        for(i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
    } 
}