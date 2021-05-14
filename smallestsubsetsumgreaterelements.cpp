#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,i;
    cin >> n;
    int a[n];
    int sum = 0;
    for(i=0;i<n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
    int ans = 0 , nextsum = 0;
    for(i=n-1; i >= 0 ;i--) {
        nextsum += a[i];
        ans++;
        sum -= a[i];
        if(nextsum > sum) break;
    }
    cout << ans << endl;
}