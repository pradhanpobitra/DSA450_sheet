#include <bits/stdc++.h>
using namespace std;

int findindex(int a[], int low, int high, int x)
{
    if (low > high)
        return INT_MAX;
    int mid = (low + high) / 2;
    if (a[mid] >= x)
        return min(mid, findindex(a, low, mid - 1, x));
    else
        return findindex(a, mid + 1, high, x);
}

int getminindex(int prefix[], int extra, int low, int high, int end, int x)
{
    if (low > high)
        return INT_MAX;
    int mid = (low + high) / 2;
    int k = end + 1 - mid;
    k = k * x;
    int sum = prefix[end] - prefix[mid - 1];
    k = k - sum;
    if (k <= extra)
        return min(mid, getminindex(prefix, extra, low, mid - 1, end, x));
    else
        return getminindex(prefix, extra, mid + 1, high, end, x);
}
int main()
{
    int n, i;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    int ans = 0;
    int s = 1;
    for (i = 1; i <= n; i++)
    {
        if (a[i] != a[s])
            s = i;
        ans = max(ans, i + 1 - s);
    }
    ans = max(ans, n + 1 - s);
    int prefix[n + 1];
    prefix[0] = 0;
    for (i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i];
    for (int x = a[1]; x <= a[n]; x++)
    {
        int m = findindex(a, 1, n, x);
        int extra;
        extra = prefix[n] - prefix[m - 1] - (n - m + 1) * x;
        int k = getminindex(prefix, extra, 1, m - 1, m - 1, x);
        if (k == INT_MAX)
            continue;
        if (k == 1)
        {
            if (prefix[m - 1] == extra)
                ans = n;
            else
                ans = max(ans, n - 1);
        }
        else
            ans = max(ans, n - k);
    }
    cout << ans << endl;
}