long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long cost = 0;
    for (long long i = 0; i < n; i++)
        pq.push(arr[i]);
    while (pq.size() > 1)
    {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        cost += x + y;
        pq.push(x + y);
    }
    return cost;
}