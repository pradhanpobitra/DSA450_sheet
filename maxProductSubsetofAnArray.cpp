#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solveUsingNlogNGreedy(ll arr[],int n) 
{
    sort(arr,arr+n);
    bool haspos = false, hasneg = false;
    ll posproduct = 1;
    ll negproduct = 1;
    for(int i=n-1;i>=0;i--) {
        if(arr[i] <= 0) break;
        posproduct *= arr[i];
        haspos = true;
    }
    for(int i=1; i< n;i+=2) {
        if(arr[i] >=0) break;
        negproduct *= arr[i] * arr[i-1];
        hasneg = true;
    }
    ll ans;
    if(haspos && hasneg) ans = posproduct * negproduct;
    else if(!haspos && !hasneg) ans = 0;
    else if(!haspos) ans = negproduct;
    else ans = posproduct;

    cout << ans << endl;
} 

void solveUsingNdp(ll arr[],int n) {
    int i;
    ll mn , mx;
    ll pmn,pmx;
    pmn = pmx = arr[0];
    for(i=1;i<n;i++) {
        mx = max( pmx , max( arr[i] * pmn , arr[i] * pmx ) );
        mn = min( pmn , min( arr[i] * pmn , arr[i] * pmx ) );
        pmx = mx;
        pmn = mn;
    }
    cout << pmx << endl;
}

int main() {
    int n,i;
    cin >> n;
    ll arr[n];
    for(i=0;i<n;i++) cin >> arr[i];

    solveUsingNlogNGreedy(arr,n);
    solveUsingNdp(arr,n);
}