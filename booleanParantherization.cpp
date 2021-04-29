class Solution{
public:
    long long dp[201][201][2];
    long long solve(string &s,int l,int r,int value) {
        if(dp[l][r][value] != -1) return dp[l][r][value];
        if(l==r) {
            if(value && s[l]=='T') return 1;
            else if(!value && s[l]=='F') return 1;
            else return 0;
        }
        long long ans  = 0;
        #define ll long long
        for(int i=l;i<r;i++) {
            if(!(s[i]=='T' || s[i]=='F')) {
                ll x = solve(s,l,i-1,1);
                ll y = solve(s,i+1,r,0);
                ll z = solve(s,l,i-1,0);
                ll p = solve(s,i+1,r,1);
                if(s[i]=='|') {
                    if(value) ans += (x * p + z * p + x * y);
                    else ans += y * z;
                }
                else if(s[i]=='&') {
                    if(value) ans += x * p;
                    else ans += x * y + z * p + y * z;
                }
                else {
                    if(value) ans += z * p + x * y;
                    else ans += x * p + y * z;
                }
            }
        }
        return dp[l][r][value] = ans % 1003;
    }
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,1);
    }
};
