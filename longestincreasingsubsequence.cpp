#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
    // your code here
    map<int, int> h;
    int mx = 1;
    h[a[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        auto it = h.lower_bound(a[i]);
        if (it == h.begin())
        {
            h[a[i]] = 1;
        }
        else
        {
            auto it2 = it;
            it--;
            h[a[i]] = it->second + 1;
            while (it2 != h.end() && it2->second <= h[a[i]])
            {
                it = ++it2;
                it2--;
                h.erase(it2);
                it2 = it;
            }
        }
        mx = max(mx, h[a[i]]);
    }
    return mx;
}