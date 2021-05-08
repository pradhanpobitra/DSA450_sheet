#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
        int id;
        int deadline;
        int profit;
        void setdata(int id,int dline,int prft) {
            id = id;
            deadline = dline;
            profit = prft;
        }
};

bool myway(const Job &a,const Job &b) {
    return a.deadline < b.deadline;
}

int solve(Job arr[],int index,int timestamp,int **dp) {
    if(index < 0 || timestamp <= 0) return 0;
    if(dp[index][timestamp]!=-1) return dp[index][timestamp];
    if(arr[index].deadline >= timestamp) return dp[index][timestamp] = max(arr[index].profit + solve(arr,index-1,timestamp-1,dp), solve(arr,index-1,timestamp,dp));
    else return dp[index][timestamp] = solve(arr,index,timestamp-1,dp);
}

int main() {
    int n,i,a,b,j,c;
    cin >> n;
    Job arr[n];
    for(i=0;i<n;i++) {
        cin >> a >> b >> c;
        arr[i].setdata(a,b,c);
    }
    sort(arr,arr+n,myway);
    int m = arr[n-1].deadline;
    // int **dp = new int*[n];
    // for(i=0;i<n;i++) dp[i] = new int[m+1];
    // for(i=0;i<n;i++) for(int j=0;j<=m;j++) dp[i][j] = -1;
    // cout << solve(arr,n-1,m,dp) << endl;
    
    int dp[n+1][m+1];
    for(i=0;i<=n;i++) {
        for(j=0;j<=m;j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(arr[i-1].deadline >= j) dp[i][j] = max(arr[i-1].profit + dp[i-1][j-1], dp[i-1][j]);
            else dp[i][j] = dp[i][j-1];
        }
    }
    i = n;
    j = m;
    int counts = 0;
    while(dp[i][j]) {
        if(arr[i-1].deadline >= j) {
            if(arr[i-1].profit + dp[i-1][j-1] == dp[i][j]) 
            {
                counts++;
                i--;
                j--;
            }
            else i--;
        }
        else j--;
    }
    cout << dp[n][m] << " " << counts << endl;
}   