int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i, j;
    i = j = 0;
    int platforms = 0;
    int maximum = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
        maximum = max(maximum, platforms);
    }
    return maximum;
}