#include<bits/stdc++.h>
using namespace std;

int get_units(vector<int> &h,int mid) {
    int sum = 0;
    for(int x : h) {
        if( x >= mid ) sum += x - mid;
    }
    return sum;
}

int main() {
    int n,i,k;
    cin >> n >> k;
    vector<int> h(n);
    for(i=0;i<n;i++) cin >> h[i];
    int r = *max_element(h.begin() , h.end());
    int l = 0;
    int ans = -1;
    while( l < r ) {
        int mid = (l + r) / 2;
        int rem_units = get_units(h,mid);
        if(rem_units == k) {
            cout << mid << endl;
            return 0;
        }
        else if(rem_units > k) l = mid + 1;
        else r = mid - 1;
    }
    cout << -1 << endl;
}