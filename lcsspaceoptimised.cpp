#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{

    // your code here
    int *previous = new int[y + 1];
    int *curr = new int[y + 1];
    for (int i = 0; i <= y; i++)
        previous[i] = 0;

    for (int i = 1; i <= x; i++)
    {
        curr[0] = 0;
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + previous[j - 1];
            else
                curr[j] = max(curr[j - 1], previous[j]);
        }
        swap(previous, curr);
    }
    return previous[y];
}