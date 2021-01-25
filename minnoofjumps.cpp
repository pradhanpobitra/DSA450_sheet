#include <bits/stdc++.h>
using namespace std;

int minJumps(int a[], int n)
{
    // Your code here
    int jumps = 0, curr = 0, mxcurrpos = 0, mxnextpos = a[0];
    if (n == 1)
        return 0;
    if (a[0] == 0)
        return -1;
    while (curr < n)
    {

        if (mxcurrpos >= n - 1)
            return jumps;
        if (curr == mxcurrpos)
        {
            jumps++;
            mxnextpos = max(mxnextpos, curr + a[curr]);
            if (mxcurrpos == mxnextpos)
                return -1;
            mxcurrpos = mxnextpos;
            curr++;
        }
        else
        {
            mxnextpos = max(mxnextpos, curr + a[curr]);
            curr++;
        }
    }
}