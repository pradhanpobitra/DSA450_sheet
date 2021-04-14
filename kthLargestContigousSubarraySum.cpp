#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int n,int k) {
    int i,j;
    priority_queue<int,vector<int>,greater<int>> pq;
    j=0;
    int sum;
    while(k) {
        sum = 0;
        i = j;
        while(k && i >= 0) {
            sum += a[i];
            i--;
            k--;
            pq.push(sum);
        }
        if(k) j++;
    }
    while(i >= 0) {
        sum += a[i];
        i--;
        if(pq.top() < sum) {
            pq.pop();
            pq.push(sum);
        }
    }
    j++;
    while(j < n) {
        i = j;
        sum = 0;
        while(i >= 0) {
            sum += a[i];
            i--;
            if(pq.top() < sum) {
                pq.pop();
                pq.push(sum);
            }
        }
        j++;
    }
    cout << pq.top() << endl;
}
int main() {
    int k, n , i;
    cin >> n >> k;
    int a[n];
    for(i=0; i<n ;i++) cin >> a[i];
    solve(a,n,k);
}