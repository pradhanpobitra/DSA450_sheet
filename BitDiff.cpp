#include <bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b)
{

    // Your logic here
    int ans = a ^ b;
    int c = 0;
    while (ans)
    {
        c++;
        ans = ans & (ans - 1);
    }
    return c;
}