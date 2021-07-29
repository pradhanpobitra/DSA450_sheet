#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &v) {
    int n = v.size();
    int first = 0;
    for(first = 0 ; first < n -1; first++) {
        if(v[first] > v[first + 1]) break;
    }
    if(first == n-1) return true;
    int second = first + 1;
    while(second < n && v[second] < v[first]) second++;
    swap(v[first],v[second-1]);

    for(int i=0;i<n-1;i++) if(v[i] > v[i+1]) return false;
    return true;
}

int main() {
    int n,x;
    vector<int> v;
    cin >> n;
    while(n--) {
        cin >> x;
        v.push_back(x);
    }
    cout << check(v);
}