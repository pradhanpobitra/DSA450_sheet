#include<bits/stdc++.h>
using namespace std;

int wordwrap(vector<int> &nums,int n,int width,int i,int dp[]) {
    if(i==n) return 0;
    if(dp[i] != -1) return dp[i];
    int k = 0;
    int mn = INT_MAX;
    for(int j=i;j<n;j++) {
        k += nums[j];
        if(k <= width) {
            int extra = width - k;
            extra = extra * extra;
            mn = min(mn , extra + wordwrap(nums,n,width,j+1,dp));
            k++;
        }
        else break;
    }
    return dp[i] = mn;
}

int main() {
    int n,i,x;
    cin >> n;
    int width;
    cin >> width;
    vector<int> nums;
    for(i=0;i<n;i++) {
        cin >> x;
        nums.push_back(x);
    }
    int dp[n];
    for(i=0;i<n;i++) dp[i] = -1;
    cout << wordwrap(nums,n,width,0,dp) << endl;;;;
    for(i=0; i < n ; i++) cout << dp[i] << " ";
}