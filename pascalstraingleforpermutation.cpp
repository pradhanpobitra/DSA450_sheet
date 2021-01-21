#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main() {
    int n,r,i,j;
    cin >> n >> r;
    if(r < 0 || n < 0 || r > n) {
        cout << 0 << endl;
        return 0;
    }
    long long npr[n+1][n+1];
    memset(npr,0,sizeof npr);
    npr[0][0]=1;
    npr[1][0]=npr[1][1]=1;
    for(i=2;i<=n;i++) {
        npr[i][0] = 1;
        for(j=1;j<=i;j++) npr[i][j] = (npr[i-1][j]%M + (j%M * npr[i-1][j-1]%M)%M)%M;
    }
    cout << npr[n][r] << endl;
}