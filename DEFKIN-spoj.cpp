#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll w, h, n, i, j, t;
    cin >> t;
    while (t--)
    {
        cin >> w >> h >> n;
        vector<ll> columns, rows;
        if (n == 0)
        {
            cout << w * h << endl;
            continue;
        }
        while (n--)
        {
            cin >> i >> j;
            columns.push_back(i);
            rows.push_back(j);
        }
        sort(columns.begin(), columns.end());
        sort(rows.begin(), rows.end());
        n = columns.size();
        ll mxcoldiff = columns[0] - 1;
        for (i = 1; i < n; i++)
            mxcoldiff = max(mxcoldiff, columns[i] - columns[i - 1] - 1);
        mxcoldiff = max(mxcoldiff, w - columns[n - 1]);
        ll mxrowdiff = max(rows[0] - 1, h - rows[n - 1]);
        for (i = 1; i < n; i++)
            mxrowdiff = max(mxrowdiff, rows[i] - rows[i - 1] - 1);
        cout << mxcoldiff * mxrowdiff << endl;
    }
}