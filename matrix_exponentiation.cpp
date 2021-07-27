#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> multiply(vector<vector<long long>> &a,vector<vector<long long>> &b) {
    vector<vector<long long>> ans(2 , vector<long long> (2 , 0));
    ans[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    ans[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    ans[1][0] = a[1][0] * b[0][0] + a[1][1] * b[0][1];
    ans[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    return ans;  
}

vector<vector<long long>> solve(vector<vector<long long>> &a,long long n)
{
    if( n == 1 ) return a;
    vector<vector<long long>> temp = solve(a , n / 2);
    vector<vector<long long>> ans = multiply(temp , temp);

    if(n % 2) ans = multiply(ans , a);
    return ans;
}
int main() {
    vector<long long> v,u,x;
    long long n;
    cin >> n;
    n--;
    vector<vector<long long>> a(2 , vector<long long> (2 , 1));
    a[1][1] = 0;
    a = solve(a , n);  
    cout << a[0][0] + a[0][1] << endl;  
}