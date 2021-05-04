class Solution {
public:
    int solve(vector<pair<int,int> > edges[],int src,int dst,int k,int **dp) {
        if(src == dst) return 0;
        if(k <= 0) return INT_MAX;
        if(dp[src][k] != -1) return dp[src][k];
        int mn = INT_MAX;
        for(pair<int,int> p : edges[src]) {
            int y = solve(edges,p.first,dst,k-1,dp);
            if(y != INT_MAX) mn = min(mn , y + p.second);
        }    
        return dp[src][k] = mn;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< pair<int,int> > edges[n];
        for(vector<int> x : flights) {
            edges[x[0]].push_back(make_pair(x[1],x[2]));
        }
        int **dp = new int*[n];
        for(int i=0;i<n;i++) dp[i] = new int[k+2];
        for(int i=0;i<n;i++) for(int j=0;j<=k+1;j++) dp[i][j] = -1;
        int ans = solve(edges,src,dst,k+1,dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};