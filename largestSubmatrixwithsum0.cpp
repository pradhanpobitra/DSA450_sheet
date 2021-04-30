#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,i,j,k;
    cin >> n >> m;
    int matrix[n+1][m+1];
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) cin >> matrix[i][j];
    int prefixsum[n+1][m+1];
    for(i=1;i<=n;i++) {
        for(j=0;j<=m;j++) {
            if(j==0) prefixsum[i][j] = 0;
            else {
                prefixsum[i][j] = prefixsum[i][j-1] + matrix[i][j];
            }
        }
    }
    int mxsize = 0;
    int sr,er,sc,ec;
    unordered_map<int,int> h;
    for(i=1;i<=m;i++) {
        for(j=i;j<=m;j++) {
            h.clear();
            int currsum = 0;
            for(k=1;k<=n;k++) {
                currsum = currsum + prefixsum[k][j] - prefixsum[k][i-1];
                if(currsum == 0) {
                    int xx = k * (j - i + 1);
                    if(xx > mxsize) {
                        mxsize = max(mxsize , xx);
                        sr = 1;
                        er = k;
                        sc = i;
                        ec = j;
                    }
                }
                else if(h[currsum]) {
                    int xx = (k - h[currsum]) * (j - i + 1);
                    if(xx > mxsize) {
                        mxsize = max(mxsize , xx);
                        sr = 1;
                        er = k;
                        sc = i;
                        ec = j;
                    }
                }
                else h[currsum] = k;
            }
        }
    }
    if(mxsize) {
        for(int row=sr;row<=er;row++) {
            for(int col=sc;col <= ec;col++) cout << matrix[row][col] << " ";
            cout << endl;
        }
    }
}