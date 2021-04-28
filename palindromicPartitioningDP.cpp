class Solution{
public:
    
    bool check(string &str,int l,int r) {
        while(l <= r) {
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int solve(string &str,int l,int r,int **dp) {
        if(dp[l][r]!=-1) return dp[l][r];
        bool ispalindrome = check(str,l,r);
        if(ispalindrome) return dp[l][r] = 0;
        int mn = r-l;
        for(int i=l;i<r;i++) {
            if(check(str,l,i)) mn = min(mn , 1 + solve(str,i+1,r,dp));
        }
        return dp[l][r]=mn;
    }
    int palindromicPartition(string str)
    {
        // code here
        int r = str.length();
        int **dp = new int*[r];
        for(int i=0;i<r;i++) dp[i] = new int[r];
        for(int i=0;i<r;i++) for(int j=0;j<r;j++) dp[i][j] = -1;
        return solve(str,0,r-1,dp);
    }
};