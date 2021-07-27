#include<bits/stdc++.h>
using namespace std;

bool check(int x,int y,int r,int c,vector<vector<int>>& grid) {
    if(x < 0 || y < 0 || x >= r || y >= c || grid[x][y] == 0) return false;
    return true;
}

int optimal_distance(vector<vector<int>> &grid) {
    int rows = grid.size() , cols = grid[0].size() , i , j;
    vector<vector<int>> min_dist(rows, vector<int> (cols, INT_MAX));
    min_dist[0][0] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()) {
        int n = q.size();
        for(i=0;i<n;i++) {
            auto p = q.front();
            int x = p.first, y = p.second;
            if(grid[x][y] == 9) return min_dist[x][y];
            q.pop();
            if(check(x+1,y,rows,cols,grid)  && min_dist[x+1][y] > min_dist[x][y] + 1) { q.push(make_pair(x+1,y)); min_dist[x+1][y] = min_dist[x][y] + 1; }
            if(check(x-1,y,rows,cols,grid)  && min_dist[x-1][y] > min_dist[x][y] + 1) { q.push(make_pair(x-1,y)); min_dist[x-1][y] = min_dist[x][y] + 1; }
            if(check(x,y+1,rows,cols,grid)  && min_dist[x][y+1] > min_dist[x][y] + 1) { q.push(make_pair(x,y+1)); min_dist[x][y+1] = min_dist[x][y] + 1; }
            if(check(x,y-1,rows,cols,grid)  && min_dist[x][y-1] > min_dist[x][y] + 1) { q.push(make_pair(x,y-1)); min_dist[x][y-1] = min_dist[x][y] + 1; }
        }
    }
    return -1;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int> (m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> grid[i][j];
    cout << optimal_distance(grid) << endl;
}