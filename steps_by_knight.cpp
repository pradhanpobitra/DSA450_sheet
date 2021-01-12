#include <bits/stdc++.h>
using namespace std;

#define ppiii pair<pair<int, int>, int>
#define mp make_pair
class Solution
{
public:
    bool valid(int x, int y, int n)
    {
        if (x < 1 || y < 1 || x > n || y > n)
            return false;
        return true;
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        // Code here
        queue<ppiii> q;
        int x = KnightPos[0], y = KnightPos[1];
        q.push(mp(mp(x, y), 0));
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
        visited[x][y] = 1;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            x = p.first.first, y = p.first.second;

            if (x == TargetPos[0] && y == TargetPos[1])
                return p.second;
            if (valid(x - 1, y - 2, n) && !visited[x - 1][y - 2])
                visited[x - 1][y - 2] = 1, q.push(mp(mp(x - 1, y - 2), p.second + 1));
            if (valid(x - 1, y + 2, n) && !visited[x - 1][y + 2])
                visited[x - 1][y + 2] = 1, q.push(mp(mp(x - 1, y + 2), p.second + 1));
            if (valid(x - 2, y - 1, n) && !visited[x - 2][y - 1])
                visited[x - 2][y - 1] = 1, q.push(mp(mp(x - 2, y - 1), p.second + 1));
            if (valid(x - 2, y + 1, n) && !visited[x - 2][y + 1])
                visited[x - 2][y + 1] = 1, q.push(mp(mp(x - 2, y + 1), p.second + 1));
            if (valid(x + 1, y + 2, n) && !visited[x + 1][y + 2])
                visited[x + 1][y + 2] = 1, q.push(mp(mp(x + 1, y + 2), p.second + 1));
            if (valid(x + 1, y - 2, n) && !visited[x + 1][y - 2])
                visited[x + 1][y - 2] = 1, q.push(mp(mp(x + 1, y - 2), p.second + 1));
            if (valid(x + 2, y - 1, n) && !visited[x + 2][y - 1])
                visited[x + 2][y - 1] = 1, q.push(mp(mp(x + 2, y - 1), p.second + 1));
            if (valid(x + 2, y + 1, n) && !visited[x + 2][y + 1])
                visited[x + 2][y + 1] = 1, q.push(mp(mp(x + 2, y + 1), p.second + 1));
        }
    }
};