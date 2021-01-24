#include <bits/stdc++.h>
using namespace std;

bool myway(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int maxChainLen(struct val p[], int n)
{
    //Your code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(p[i].first, p[i].second));
    sort(v.begin(), v.end(), myway);
    int dp[n];
    dp[0] = 1;
    int mx = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[i].first > v[j].second)
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        mx = max(mx, dp[i]);
    }
    return mx;
}