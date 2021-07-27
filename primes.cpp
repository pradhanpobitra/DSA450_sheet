#include<bits/stdc++.h>
using namespace std;


int main() {
    bool primes[1000001];
    for(int i=0;i<=1000000;i++) primes[i] = 1;
    primes[0] = primes[1] = false;
    for(int i=2;i*i<=1000000;i++) {
        if(primes[i]) {
            for(int j=2;j*i<=1000000;j++) primes[j*i] = false;
        }
    }
    int count = 0;
    for()
}