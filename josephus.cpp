#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int solve(bool alive[],int n,int k,int s,int alivecount) {
    if(alivecount == 1) return s;
    int count = 0;
    int i = s;
    while(count < k-1) {
        if(alive[i]) count++;
        i++;
        i %= n;
    }
    while(!alive[i]) {
        i++;
        i %= n;
    }
    alive[i] = false;
    i++;
    i %= n;
    while(!alive[i]) {
        i++;
        i %= n;
    }
    return solve(alive,n,k,i,alivecount-1);
}

int main() {
    int n,k;
    cin >> n >> k;
    bool alive[n];
    memset(alive,1,sizeof(alive));
    cout << solve(alive,n,k,0,n);
}