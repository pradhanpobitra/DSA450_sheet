long long solve(long long n,vector<long long> &v) {
    long long dp[3+1][n+1];
    for(int i=0;i<=3;i++) {
        for(int j=0;j<=n;j++) {
            if(j==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = 0;
            else if(j >= v[i-1]) dp[i][j] = dp[i][j-v[i-1]] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[3][n];
}
long long int count(long long int n)
{
	vector<long long> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(10);
	return solve(n,v);
}