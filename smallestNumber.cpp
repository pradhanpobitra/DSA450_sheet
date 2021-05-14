string smallestNumber(int S, int D)
{
    // code here
    string ans;
    if (D * 9 < S)
        return "-1";
    while (D)
    {
        if (D == 1)
        {
            ans.push_back('0' + S);
            S = 0;
            D = 0;
            break;
        }
        int rem = S - 1;
        if (rem >= 9)
        {
            ans.push_back('9');
            S -= 9;
            D--;
        }
        else
        {
            ans.push_back('0' + rem);
            S -= rem;
            D--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}