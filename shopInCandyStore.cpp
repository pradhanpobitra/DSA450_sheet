vector<int> candyStore(int candies[], int N, int K)
{
    // Write Your Code here
    sort(candies, candies + N);
    int i = 0, j = N - 1;
    int mn = 0, mx = 0;
    while (i <= j)
    {
        mn += candies[i];
        j -= K;
        i++;
    }
    i = 0, j = N - 1;
    while (i <= j)
    {
        mx += candies[j];
        i += K;
        j--;
    }
    vector<int> ans;
    ans.push_back(mn);
    ans.push_back(mx);
    return ans;
}