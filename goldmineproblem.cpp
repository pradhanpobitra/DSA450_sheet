#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,i,j;
    cin >> n >> m;
    int matrix[n][m];
    for(i=0;i<n;i++) for(j=0;j<m;j++) cin >> matrix[i][j];
    for(j=1;j<m;j++) {
        matrix[0][j] = matrix[0][j] + max(matrix[0][j-1],matrix[1][j-1]);
        matrix[n-1][j] = matrix[n-1][j] + max(matrix[n-1][j-1],matrix[n-2][j-1]);
        for(i=1;i<n-1;i++) {
            matrix[i][j] = matrix[i][j] + max( matrix[i][j-1] , max( matrix[i-1][j-1], matrix[i+1][j-1] ));
        }
    }
    int ans = 0;
    for(i=0;i<n;i++) ans = max(ans, matrix[i][m-1]);
    cout << ans << endl;
}