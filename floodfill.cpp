#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define mp make_pair
    bool valid(int x, int y, int rows, int cols)
    {
        if (x < 0 || y < 0 || x >= rows || y >= cols)
            return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newcolor)
    {
        vector<vector<int>> newimage = image;
        int rows = image.size(), cols = image[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int prevcolor = image[sr][sc];
        queue<pair<int, int>> q;
        newimage[sr][sc] = newcolor;
        q.push(mp(sr, sc));
        vis[sr][sc] = 1;
        while (!q.empty())
        {
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            if (valid(x, y + 1, rows, cols) && image[x][y + 1] == prevcolor && !vis[x][y + 1])
            {
                newimage[x][y + 1] = newcolor;
                vis[x][y + 1] = 1;
                q.push(mp(x, y + 1));
            }
            if (valid(x, y - 1, rows, cols) && image[x][y - 1] == prevcolor && !vis[x][y - 1])
            {
                newimage[x][y - 1] = newcolor;
                vis[x][y - 1] = 1;
                q.push(mp(x, y - 1));
            }
            if (valid(x + 1, y, rows, cols) && image[x + 1][y] == prevcolor && !vis[x + 1][y])
            {
                newimage[x + 1][y] = newcolor;
                vis[x + 1][y] = 1;
                q.push(mp(x + 1, y));
            }
            if (valid(x - 1, y, rows, cols) && image[x - 1][y] == prevcolor && !vis[x - 1][y])
            {
                newimage[x - 1][y] = newcolor;
                vis[x - 1][y] = 1;
                q.push(mp(x - 1, y));
            }
        }
        return newimage;
    }
};