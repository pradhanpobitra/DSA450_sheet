bool way(const vector<int> &a,const vector<int> &b) {
    return a[1] < b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),way);
        int n = pairs.size();
        int dp[n];
        dp[0] = 1;
        int ans = 1;
        for(int i=1;i<n;i++) {
            dp[i] = 1;
            for(int j=i-1;j>=0;j--) {
                if(pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i],1 + dp[j]);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};