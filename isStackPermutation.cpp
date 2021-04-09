#include<bits/stdc++.h>
using namespace std;

bool check(int arr1[],int arr2[],int n) {
    unordered_map<int,bool> ht;
    int ptr1, ptr2;
    ptr1 = ptr2 = 0;
    stack<int> st;
    while(ptr2 < n) {
        if(ht[arr2[ptr2]] == false) {
            while(ptr1<n && arr1[ptr1] != arr2[ptr2]) {
                st.push(arr1[ptr1]);
                ht[arr1[ptr1]] = true;
                ptr1++;
            }
            if(ptr1 == n) return false;
            ptr1++;
            ptr2++;
        }
        else {
            if(st.top() != arr2[ptr2]) return false;
            st.pop();
            ptr2++;
        }
    }
    if(!st.empty()) return false;
    return true;
}

int main() {
    int n,i;
    cin >> n;
    int arr1[n] , arr2[n];
    for(i=0;i<n;i++) cin >> arr1[i];
    for(i=0;i<n;i++) cin >> arr2[i];
    if(check(arr1,arr2,n)) cout << "Yes";
    else cout << "No";
}