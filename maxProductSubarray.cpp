long long maxProduct(int *arr, int n)
{
    // code here
    long long pmx = arr[0];
    long long pmn = arr[0];
    long long mx = pmx, mn = pmn, ans = pmx;
    for (int i = 1; i < n; i++)
    {
        mx = max(pmx * arr[i], max(pmn * arr[i], (long long)arr[i]));
        mn = min(pmx * arr[i], min(pmn * arr[i], (long long)arr[i]));
        pmx = mx;
        pmn = mn;
        ans = max(ans, mx);
    }
    return ans;
}