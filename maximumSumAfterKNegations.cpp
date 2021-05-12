class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        int countofneg = 0;
        for(int i=0;i<n;i++) {
            if(a[i] >= 0) break;
            countofneg++;
        }
        long long sum = 0;
        if(countofneg == 0) {
            if(k%2) a[0] = -a[0];
            for(int i=0;i<n;i++) sum += a[i];
        }
        else if(countofneg >= k) {
            while(k) {
                a[k-1] = -a[k-1];
                k--;
            }
            for(int i=0;i<n;i++) sum += a[i];
        }
        else {
            int x = countofneg;
            while(countofneg) {
                a[countofneg-1] = -a[countofneg-1];
                countofneg--;
            }
            k -= x;
            if(k%2) {
                if(a[x] < a[x-1]) a[x] = -a[x];
                else a[x-1] = -a[x-1];
            }
            for(int i=0;i<n;i++) sum += a[i];
        }
        return sum;
    }
};