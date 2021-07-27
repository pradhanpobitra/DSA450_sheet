#include <bits/stdc++.h>
using namespace std;

bool has_square(vector<vector<int>> &prefix, int size)
{
    int rows = prefix.size(), cols = prefix[0].size();
    for (int i = size; i < rows; i++)
    {
        for (int j = size; j < cols; j++)
        {
            int sum = prefix[i][j] - prefix[i][j - size] - prefix[i - size][j] + prefix[i - size][j - size];
            if (sum == size * size)
                return true;
        }
    }
    return false;
}
int maximalSquare(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size(), i, j;
    vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= cols; j++)
        {
            prefix[i][j] = matrix[i - 1][j - 1] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
            cout << prefix[i][j] <<  " ";
        }
        cout << endl;
    }
    
    int l = 1, h = min(rows, cols);
    int ans = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (has_square(prefix, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }

    return ans * ans;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> mat[i][j];
    cout << maximalSquare(mat);
}