#include<bits/stdc++.h>
using namespace std;

int main() {
    int p,q,r,i,j,k;
    cin >> p >> q >> r;
    int s1[p], s2[q] , s3[r];
    int sum1 = 0 , sum2 = 0 , sum3 = 0;
    for(i=0;i<p;i++) { cin >> s1[i]; sum1 += s1[i]; }
    for(i=0;i<q;i++) { cin >> s2[i]; sum2 += s2[i]; }
    for(i=0;i<r;i++) { cin >> s3[i]; sum3 += s3[i]; }
    i = j = k = 0;
    while(i < p && j < q && k < r) {
        if(sum1 == sum2 && sum1 == sum3) break;
        if(sum1 <= sum2 && sum1 <= sum3) {
            sum2 -= s2[j];
            j++;
            sum3 -= s3[k];
            k++;
        }
        else if(sum2 <= sum1 && sum2 <= sum3) {
            sum1 -= s1[i++];
            sum3 -= s3[k++];
        }
        else {
            sum1 -= s1[i++];
            sum2 -= s2[j++];
        }
    }
    if(i < p && j < q && k < r) cout << sum1 << endl;
    else cout << 0 << endl;
}