#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        int c = 0;
        while (N)
        {
            c++;
            N = N & (N - 1);
        }
        return c;
    }
};