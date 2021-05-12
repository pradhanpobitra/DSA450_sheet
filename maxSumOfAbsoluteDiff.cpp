#include<bits/stdc++.h>
using namespace std;

int main() {
    int j,n,i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    i = 0;
    j = n-1;
    int sum = 0;
    while(1) {
        if(i < j) {
            sum += a[j] - a[i];
            i++;
            if(i < j) {
                sum += a[j] - a[i];
                j--;
            }
            else break;
        }
        else break;
    }
    sum += a[i] - a[0];
    cout << sum << endl;
}