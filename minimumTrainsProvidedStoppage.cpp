#include<bits/stdc++.h>
using namespace std;
bool myway(const pair<vector<string>,int> &a,const pair<vector<string>,int> &b) {
    if(a.first[1]==b.first[1]) return a.first[0] < b.first[0];
    return a.first[1] < b.first[1];
}
int main() {
    int n,m,i;
    string a,d;
    int p;
    cin >> n >> m;
    vector< pair<vector<string>,int> > v;
    while(m--) {
        cin >> a >> d >> p;
        vector<string> x;
        x.push_back(a);
        x.push_back(d);
        v.push_back(make_pair(x,p));
    }
    sort(v.begin(),v.end(),myway);
    for(pair<vector<string>,int> x : v) cout << x.first[0] << " " << x.first[1] << " " << x.second << endl;
    string lastdep[n+1];
    int mxcount = 0;
    for(pair<vector<string>,int> x : v) {
        if(lastdep[x.second].size() == 0) {
            mxcount++;
            lastdep[x.second] = x.first[1];
        }
        else {
            if(x.first[0] >= lastdep[x.second]) {
                mxcount++;
                lastdep[x.second] = x.first[1];
            }
        }
    }
    cout << mxcount << endl;
}