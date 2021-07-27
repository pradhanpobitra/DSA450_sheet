#include<bits/stdc++.h>
using namespace std;


int main() {
    long long n, a,b , c;
    a = 1, b = 1;
    cin >> n;
    n--;
    while(n) {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    cout << b;
}