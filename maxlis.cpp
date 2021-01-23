#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        int lis[n];
        for (int i = 0; i < n; i++)
        {
            lis[i] = arr[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < arr[i])
                    lis[i] = max(lis[i], arr[i] + lis[j]);
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, lis[i]);
        return mx;
    }
};