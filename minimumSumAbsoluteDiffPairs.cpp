#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i;
    cin >> n;
    int a[n],b[n];
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int sum = 0;
    for(i=0;i<n;i++) sum += abs(a[i]-b[i]);
    cout << sum << endl;
}