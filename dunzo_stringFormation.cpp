#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

long long solve(string& target,int tindx,vector<vector<int>> &f,int mxindex,vector<vector<long long>> &dp) {
    if(tindx < 0) return 1;
    if(mxindex < 0) return 0;
    if(dp[tindx][mxindex] != -1) return dp[tindx][mxindex];
    return dp[tindx][mxindex] = ((solve(target,tindx-1,f,mxindex-1,dp) * f[mxindex][target[tindx] - 'a'])%M + solve(target,tindx,f,mxindex-1,dp))%M;
}


int main() {
    int n,mxindx;
    string target;
    cin >> n;
    vector<string> strs;
    while(n--) {
        cin >> target;
        mxindx = target.size();
        strs.push_back(target);
    }
    cin >> target;
    vector<vector<int>> f(mxindx, vector<int> (26, 0));
    for(string s : strs) {
        for(int i=0;s[i]!='\0';i++) f[i][s[i]-'a']++;
    }
    n = target.size();
    vector<vector<long long>> dp(n,vector<long long> (mxindx,-1));
    cout << solve(target,n-1,f,mxindx-1,dp);
}