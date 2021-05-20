#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &row, int cand, int l, int h)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (row[mid] <= cand)
    {
        return max(mid, search(row, cand, mid + 1, h));
    }
    return search(row, cand, l, mid - 1);
}
int solve(vector<vector<int>> &mat, int cand, int r, int c)
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        sum += search(mat[i], cand, 0, c - 1) + 1;
    }
    return sum;
}

int median(vector<vector<int>> &matrix, int r, int c)
{
    // code here
    int mn = INT_MAX;
    int mx = INT_MIN;
    int i, j;
    int no = (r * c) / 2 + 1;
    for (i = 0; i < r; i++)
        mn = min(mn, matrix[i][0]), mx = max(mx, matrix[i][c - 1]);
    int l = mn, h = mx;
    while (1)
    {
        int mid = (l + h) / 2;
        int countswmid = solve(matrix, mid, r, c);
        int countswomid = solve(matrix, mid - 1, r, c);
        if (countswomid < no && countswmid >= no)
            return mid;
        else if (countswomid >= no)
            h = mid - 1;
        else
            l = mid + 1;
    }
}

int main()
{
    int r, c, x;
    cin >> r >> c;
    vector<vector<int>> mat;
    for (int i = 0; i < r; i++)
    {
        vector<int> v;
        for (int j = 0; j < c; j++)
        {
            cin >> x;
            v.push_back(x);
        }
        mat.push_back(v);
    }
    int med = median(mat, r, c);
    cout << med << endl;
}