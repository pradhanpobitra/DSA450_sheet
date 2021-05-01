#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int dp[101][101][101];
    /*You are required to complete this method */
    bool solve(string &a,string &b,string &c,int p,int q,int r) {
        if(r <= 0) {
            if(p <= 0 && q <= 0) return dp[p][q][r] = 1;
            return dp[p][q][r] = 0;
        }
        if(p <= 0 && q <= 0) return dp[p][q][r] = false;
        if(p > 0 && q > 0) {
            if(c[r-1]==a[p-1] && c[r-1]==b[q-1]) return dp[p][q][r] = solve(a,b,c,p-1,q,r-1) || solve(a,b,c,p,q-1,r-1);
            if(c[r-1]==a[p-1]) return dp[p][q][r] = solve(a,b,c,p-1,q,r-1);
            if(c[r-1]==b[q-1]) return dp[p][q][r] = solve(a,b,c,p,q-1,r-1);
            return false;
        }
        else if(p > 0) {
            if(c[r-1]==a[p-1]) return dp[p][q][r] = solve(a,b,c,p-1,q,r-1);
            return dp[p][q][r] = false;
        }
        else if(q > 0) {
            if(c[r-1]==b[q-1]) return dp[p][q][r] = solve(a,b,c,p,q-1,r-1);
            return dp[p][q][r] = false;
        }
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int p = A.length() , q = B.length() , r = C.length();
        memset(dp,-1,sizeof(dp));
        return solve(A,B,C,p,q,r);
    }

};