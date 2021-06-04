#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
int maxmask;
void solve(vector<int> &nums, vector<int> &v, int mask, int size)
{
    if (mask == maxmask)
    {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if ((mask & (1 << (size - 1 - i))) == 0)
        {
            v.push_back(nums[i]);
            solve(nums, v, mask | (1 << (size - i - 1)), size);
            v.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> v;
    int n = nums.size();
    maxmask = (1 << n) - 1;
    solve(nums, v, 0, n);
    return ans;
}

int main() {
    int n,x;
    cin >> n;
    vector<int> v;
    while(n--) {
        cin >> x;
        v.push_back(x);
    }
    vector<vector<int>> vv = permute(v);
    for(vector<int> xx : vv) {
        for(int yy : xx) cout << yy << " ";
        cout << endl;
    }
}