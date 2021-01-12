#include <bits/stdc++.h>
using namespace std;
#define MAX 5
bool check(int i, int j, int n)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return false;
    return true;
}
void solve(vector<vector<int>> &m, int n, int i, int j, string &s, vector<string> &ans, vector<vector<bool>> &visited)
{
    if (!check(i, j, n))
        return;
    if (m[i][j] == 0)
        return;
    if (visited[i][j])
        return;

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }
    visited[i][j] = true;

    s.push_back('R');
    solve(m, n, i, j + 1, s, ans, visited);
    s.pop_back();

    s.push_back('L');
    solve(m, n, i, j - 1, s, ans, visited);
    s.pop_back();

    s.push_back('U');
    solve(m, n, i - 1, j, s, ans, visited);
    s.pop_back();

    s.push_back('D');
    solve(m, n, i + 1, j, s, ans, visited);
    s.pop_back();

    visited[i][j] = false;
}
vector<string> findPath(int m[MAX][MAX], int n)
{
    // Your code goes here
    vector<vector<int>> mat;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        x.clear();
        for (int j = 0; j < n; j++)
        {
            x.push_back(m[i][j]);
        }
        mat.push_back(x);
    }
    vector<string> ans;
    string t;

    solve(mat, n, 0, 0, t, ans, visited);
    sort(ans.begin(), ans.end());
    return ans;
}