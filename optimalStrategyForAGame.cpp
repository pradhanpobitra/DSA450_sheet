long long solve(int arr[],int l,int r,long long **dp) {
    if(l > r) return 0;
    if(l == r) return arr[l];
    if(l+1 == r) return max(arr[l],arr[r]);
    if(dp[l][r]!=-1) return dp[l][r];
    long long ans = 0;
    ans = max(arr[l] + min(solve(arr,l+2,r,dp) ,solve(arr,l+1,r-1,dp)), arr[r] + min(solve(arr,l+1,r-1,dp),solve(arr,l,r-2,dp)));
    return dp[l][r] = ans;
}

long long maximumAmount(int arr[], int n) 
{
    // Your code here
    long long **dp = new long long*[n];
    for(int i=0;i<n;i++) dp[i] = new long long[n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = -1;
    return solve(arr,0,n-1,dp);
}