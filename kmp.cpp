#include<bits/stdc++.h>
using namespace std;

bool solve(string& s,string& p) {
    int n = p.length();
    int lps[n];
    int i = 0, j =1;
    lps[0] = 0;
    while(j < n) {
        if(p[i] == p[j]) {
            lps[j] = i+1;
            i++;
            j++;
        } 
        else {
            if(i == 0) lps[j++] = 0;
            else i = lps[i-1];
        }
    }
    i = 0 , j = 0;
    int m = s.length();
    while(i < m) {
        if(s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            if(j == 0) i++;
            else j = lps[j-1];
        }
        if( j == n ) return true;
    }
    return false;
}

int main() {
    string s,p;
    cin >> s >> p;
    cout << solve(s,p);
}