#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    bool dp[n+1];
    dp[0] = dp[1] = true;
    for(int i=2;i<=n;i++) {
        if(i==x || i==y) dp[i] = true;
        else {
            bool canwin = false;
            if(i >= 1 && dp[i-1]==false) canwin = true;
            if(i >=x && dp[i-x] == false) canwin = true;
            if(i >= y && dp[i-y]==false) canwin = true;
            dp[i] = canwin; 
        }
    }
    cout << dp[n] << endl;
}