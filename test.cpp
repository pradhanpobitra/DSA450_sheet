#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pipii pair< int, pair<int,int> > 
bool myway(const pipii &a,const pipii &b) {
    if(a.second.first==b.second.first) {
        if(a.second.second == b.second.second) return a.first > b.first;
        else return a.second.second > b.second.second;
    } 
    return a.second.first > b.second.first;
}
int main() {
    int n;
    int id,s0,s1,s2,s3,s4;
    cin >> n;
    if(n==0) return 0;
    int i;
    i=1;
    vector< pipii > list;
    while (i <= n)
    {
        cin >> id >> s0 >> s1 >> s2 >> s3 >> s4;
        if(s0 >= 35 && s1 >= 35 && s2 >= 35 && s3 >= 35 && s4 >= 35) {
            list.pb(mp(id,mp(s0+s1+s2,s0+s1+s2+s3+s4)));
        }
        i++;

    }
    sort(list.begin(),list.end(),myway);
    for(auto p : list) {
        cout << p.first << " ";
    }
}