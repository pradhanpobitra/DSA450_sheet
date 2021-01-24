#include <bits/stdc++.h>
using namespace std;
int main()
{
    //code
    int t, n, i, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int l, h;
        cin >> k;
        h = n - 1;
        l = h - 1;
        int sum = 0;
        while (h > 0 && l >= 0)
        {
            if (a[h] - a[l] < k)
            {
                sum += a[h] + a[l];
                h = l - 1;
                l = h - 1;
            }
            else
            {
                h--;
                l--;
            }
        }
        cout << sum << endl;
    }
}