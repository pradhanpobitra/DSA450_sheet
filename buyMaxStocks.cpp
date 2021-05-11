#include<bits/stdc++.h>
using namespace std;

bool myway(const pair<int,int> &a,const pair<int,int> &b) {
    return a.first < b.first;
}

int main() {
    int n,x,i,k;
    cin >> n >> k;
    vector<pair<int,int>> v;
    for(i=1;i<=n;i++) {
        cin >> x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(),v.end(),myway);
    int count = 0;
    i=0;
    while(1) {
        if(i >= n || v[i].first > k) break;
        int buyable = k / v[i].first;
        if(buyable >= v[i].second) {
            count += v[i].second;
            k -= v[i].second * v[i].first;
        }
        else {
            count += buyable;
            k -= buyable * v[i].first;
        }
        i++;
    }
    cout << count << endl;
}