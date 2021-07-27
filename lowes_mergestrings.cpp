#include<bits/stdc++.h>
using namespace std;


char* MergeStrings(char* str1,char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);

    char *ans = new char[n+m+1];
    int l = 0, r = n+m-1;
    int i = 0;
    while(i < n && i < m) {
        if(str1[i] < str2[i]) {
            ans[l] = str1[i];
            ans[r] = str2[i];
        }
        else {
            ans[l] = str2[i];
            ans[r] = str1[i];
        }
        l++;
        r--;
        i++;
    }
    while(i < n) {
        ans[l++] = str1[i++];
    }
    while(i < m) {
        ans[l++] = str2[i++];
    }
    ans[n+m] = '\0';
    return ans;
}

int main() {
    int n,m;
    cin >> n >> m;
    char *a = new char[n+1];
    char *b = new char[m+1];
    string s, t;
    cin >> s >> t;
    int i = 0;
    while(i < n) a[i++]  = s[i];
    a[n] = '\0';
    i = 0;
    while(i < m) b[i++] = t[i];
    b[m] = '\0';
    puts(MergeStrings(a,b));
}