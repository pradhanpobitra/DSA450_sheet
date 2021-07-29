#include<bits/stdc++.h>
using namespace std;

double sqroot(double n) {
    int l = 0, h = n;
    double  ans=0;
    int mid;
    while(l < h) {
        mid = (l + h) / 2;
        if(mid * mid > n) h = mid - 1;
        else { 
            l = mid + 1;
            ans = mid;
        }
    }
    double decimal = 0.1;
    double x= ans;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=9;j++) {
            double temp = x + (j * decimal);
            if(temp * temp > n) break;
            ans = temp;
        }
        decimal /= 10;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(3) << sqroot(n) << endl;
}