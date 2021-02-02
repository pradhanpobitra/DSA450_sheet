int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int currsum = arr[0];
    int mxsum = currsum;
    for(int i=1;i<n;i++) {
        currsum = max(currsum + arr[i],arr[i]);
        mxsum = max(mxsum,currsum);
    }
    return mxsum;
}