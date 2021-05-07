#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,m,u,v;
    cin >> n >> m;
    vector< vector<int> > A(n, vector<int> (n,0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(A[i][j] && A[j][k] && A[k][i]) ans++;
            }
        }
    }
    cout << ans / 3 << endl;
}