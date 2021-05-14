#include <bits/stdc++.h>
using namespace std;
bool myway(const int &a, const int &b)
{
    return a > b;
}
int main()
{
    int t, m, n, i, j;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        m--;
        n--;
        int vertical[m], horizontal[n];
        for (i = 0; i < m; i++)
            cin >> vertical[i];
        for (i = 0; i < n; i++)
            cin >> horizontal[i];
        sort(vertical, vertical + m, myway);
        sort(horizontal, horizontal + n, myway);
        i = 0, j = 0;
        int hp = 1, vp = 1;
        int totalcost = 0;
        while (i < m && j < n)
        {
            if (vertical[i] >= horizontal[j])
            {
                totalcost += vertical[i] * hp;
                vp++;
                i++;
            }
            else
            {
                totalcost += horizontal[j] * vp;
                hp++;
                j++;
            }
        }
        while (i < m)
        {
            totalcost += vertical[i] * hp;
            vp++;
            i++;
        }
        while (j < n)
        {
            totalcost += horizontal[j] * vp;
            hp++;
            j++;
        }
        cout << totalcost << endl;
    }
}