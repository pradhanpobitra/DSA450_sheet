#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned int a,b;
    int c,d;
    int count = 0;
    cin >> c >> d;
    a = (unsigned int)(c);
    b = (unsigned int)(d);
    int i=31;
    while(i >= 0) {
        if( (b << i) <= a ) {
            count += (1 << i);
            a -= (b << i);
        }
        i--;
    }
    if(c < 0 && d < 0) cout << count;
    else if(c < 0) cout << -count;
    else if(d < 0) cout << -count;
    else cout << count;
}