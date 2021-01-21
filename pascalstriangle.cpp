#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
class Solution
{
public:
    int nCr(int n, int r)
    {
        // code here
        long long ncr[n + 1][n + 1];
        int i, j;
        if (r > n)
            return 0;
        ncr[0][0] = 1;
        ncr[1][0] = 1;
        ncr[1][1] = 1;
        ncr[1][2] = 0;
        for (i = 2; i <= n; i++)
        {
            ncr[i][0] = 1;
            for (j = 1; j < i; j++)
                ncr[i][j] = (ncr[i - 1][j] % M + ncr[i - 1][j - 1] % M) % M;
            ncr[i][i] = 1;
        }
        return ncr[n][r] % M;
    }
};