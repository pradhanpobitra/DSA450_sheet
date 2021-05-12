int Maximize(int a[], int n)
{
// Complete the function
#define M 1000000007
    sort(a, a + n);
    long long i, sum = 0;
    for (i = 0; i < (long long)n; i++)
    {
        sum = (sum % M + (i * a[i] % M) % M) % M;
    }
    return sum;
}