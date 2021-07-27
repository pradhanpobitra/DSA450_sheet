#include<bits/stdc++.h>
using namespace std;

void print_smallest_k_elements(vector<int>& v,int &k) {
    nth_element(v.begin() , v.begin() + k - 1 , v.end() , [&] (const int a,const int b) {
        return a < b;
    });
    for(int i=0;i<k;i++) cout << v[i] << " ";
}

int main() {
    vector<int> v;
    int n,k,x;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> x;
        v.push_back(x);
    }
    print_smallest_k_elements(v,k);
}