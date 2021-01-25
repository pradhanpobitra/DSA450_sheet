#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubstring(string S)
    {
        // Your code goes here
        int mx = 0;
        if (S[0] == '0')
            mx = 1;
        else
            mx = -1;
        int count = mx;
        int mn = mx;
        for (int i = 1; S[i] != '\0'; i++)
        {
            if (S[i] == '1')
                count--;
            else
                count++;
            mx = max(mx, count);
            mx = max(mx, count - mn);
            mn = min(mn, count);
        }
        return mx;
    }
};