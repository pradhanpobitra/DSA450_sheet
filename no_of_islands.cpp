#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool visited[501][501];
    bool valid(int i, int j, int r, int c)
    {
        if (i < 0 || j < 0 || i >= r || j >= c)
            return false;
        return true;
    }
    void dfs(vector<vector<char>> &grid, int i, int j, int r, int c)
    {
        if (!valid(i, j, r, c))
            return;
        if (visited[i][j] || grid[i][j] == '0')
            return;
        visited[i][j] = true;
        dfs(grid, i - 1, j - 1, r, c);
        dfs(grid, i - 1, j, r, c);
        dfs(grid, i - 1, j + 1, r, c);
        dfs(grid, i, j + 1, r, c);
        dfs(grid, i + 1, j + 1, r, c);
        dfs(grid, i + 1, j, r, c);
        dfs(grid, i + 1, j - 1, r, c);
        dfs(grid, i, j - 1, r, c);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int i, j;
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();
        if (cols == 0)
            return 0;
        memset(visited, 0, sizeof visited);
        int nums = 0;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    nums++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return nums;
    }
};