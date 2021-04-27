#include<bits/stdc++.h>
using namespace std;

int getmin(int arr[],int low,int high) {
    int mn = arr[low];
    for(int i=low+1;i<=high;i++) mn = min(mn,arr[i]);
    return mn;
}

int solve(int arr[],int low,int high,int k) {
    if(k==0 || low >= high) return 0;
    int mxprofit = 0;
    int currprofit;
    for(int i=low+1; i<=high; i++) {
        currprofit = arr[i] - getmin(arr,low,i-1) + solve(arr,i+1,high,k-1);
        mxprofit = max(mxprofit,currprofit);
    }
    return mxprofit;
}

int main() {
    int n,i;
    cin >> n;
    int arr[n];
    for(i=0;i<n;i++) cin >> arr[i];
    cout << solve(arr,0,n-1,2) << endl;
}