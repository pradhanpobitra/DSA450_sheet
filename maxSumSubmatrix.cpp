class Solution {
  public:
    int kadanes(int arr[],int r) {
        int currmax = arr[0] , megamax = arr[0] , i;
        for(i=1;i<r;i++) {
            currmax = max(currmax + arr[i],arr[i]);
            megamax = max(megamax,currmax);
        }
        return megamax;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> &M) {
        // code here
        int arr[R];
        int i,j,k;
        int mx = INT_MIN;
        for(i=0;i<C;i++) {
            memset(arr,0,sizeof(arr));
            for(j=i;j<C;j++) {
                for(k=0;k<R;k++) arr[k] += M[k][j];
                mx = max(mx, kadanes(arr,R));
            }
        }
        return mx;
    }
};
