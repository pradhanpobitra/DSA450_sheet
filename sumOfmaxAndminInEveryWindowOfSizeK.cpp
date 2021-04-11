#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int n,int k) {
    deque<int> mn,mx;
    int sum = 0;
    mn.push_back(0);
    mx.push_back(0);
    for(int i=1;i<k;i++) {
        while(!mn.empty() && a[mn.back()] > a[i]) mn.pop_back();
        mn.push_back(i);
        while(!mx.empty() && a[mx.back()] < a[i]) mx.pop_back();
        mx.push_back(i);
    }
    sum = a[mn.front()] + a[mx.front()];
    for(int i=k; i<n;i++) {
        while(!mn.empty() && a[mn.back()] > a[i]) mn.pop_back();
        mn.push_back(i);
        while(!mx.empty() && a[mx.back()] < a[i]) mx.pop_back();
        mx.push_back(i);
        if(i - mn.front() >= k) mn.pop_front();
        if(i - mx.front() >= k) mx.pop_front();
        sum += a[mn.front()] + a[mx.front()];
    }
    cout << sum << endl;
}
int main() {
    int n,k;
    cin >> n >> k;
    int i, a[n];
    for(i=0; i<n;i++) cin >> a[i];
    solve(a,n,k);
}