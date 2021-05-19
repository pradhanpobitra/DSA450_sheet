vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int xx = 0;
    for (int y : nums)
        xx = xx ^ y;
    int mask = xx & ~(xx - 1);
    int x = 0, y = 0;
    for (int a : nums)
    {
        if (mask & a)
            y = y ^ a;
        else
            x = x ^ a;
    }
    vector<int> v;
    if (x <= y)
    {
        v.push_back(x);
        v.push_back(y);
    }
    else
    {
        v.push_back(y);
        v.push_back(x);
    }
    return v;
}