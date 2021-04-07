#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int nse[],int n) {
    stack<int> s;
    for(int i=0; i < n;i++) {
        while(!s.empty() && arr[s.top()] > arr[i]) {
            nse[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        nse[s.top()] =-1;
        s.pop();
    }
}
int main() {
    int n,i;
    cin >> n;
    int arr[n];
    for(i=0; i < n ;i++) cin >> arr[i];
    int nse[n];
    solve(arr,nse,n);
    for(i=0; i < n ;i++) cout << nse[i] << " ";
}