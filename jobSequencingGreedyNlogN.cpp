#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    static bool myway(const Job &a,const Job &b) {
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,Solution::myway);
        int mxdead = 0;
        for(int i=0;i<n;i++) mxdead = max(mxdead , arr[i].dead);
        bool space[mxdead+1] = {0};
        int count = 0, profit = 0;
        for(int i=0;i<n;i++) {
            for(int j=arr[i].dead;j>=1;j--) {
                if(space[j]==0) {
                    profit += arr[i].profit;
                    space[j] = 1;
                    count++;
                    break;
                }
            }
        }
        vector<int> v;
        v.push_back(count);
        v.push_back(profit);
        return v;
    } 
};
