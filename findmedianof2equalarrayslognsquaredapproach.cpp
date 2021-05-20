#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int l,int h,int candidate) {
    if(l > h) return -1;
    int mid = (l+h)/2;
    if(arr[mid] <= candidate) return max(mid,search(arr,mid+1,h,candidate));
    else return search(arr,l,mid-1,candidate);
}

double solve(int arr1[],int arr2[],int l,int h,int no) {
    if(l > h) return (double) INT_MAX;
    int mid = (l+h)/2;
    int candidate = arr2[mid];
    int nltc = search(arr1,0,no-1,candidate);
    if(mid + nltc + 1 == no) {
        if(nltc == -1) return (double) (arr2[mid] + arr2[mid-1]) / 2;
        if(mid == 0) return (double) (arr2[mid] + arr1[nltc]) / 2;
        return (double) (arr2[mid] + max(arr2[mid-1],arr1[nltc])) / 2;
    }
    else if(mid + nltc + 1 > no) return solve(arr1,arr2,l,mid-1,no);
    else return solve(arr1,arr2,mid+1,h,no);
}

int main() {
    int n,i;
    cin >> n;
    int arr1[n],arr2[n];
    for(i=0;i<n;i++) cin >> arr1[i];
    for(i=0;i<n;i++) cin >> arr2[i];
    double median = solve(arr1,arr2,0,n-1,n);
    if(median == (double) INT_MAX) {
        median = solve(arr2,arr1,0,n-1,n);
    }
    cout << median << endl;
}