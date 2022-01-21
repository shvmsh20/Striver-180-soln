long long merge(long long *arr, int lo, int mid, int hi){
    int n1 =  mid-lo+1, n2 = hi-mid;
    int a[n1];
    int b[n2];
    long long ans=0;
    for(int i=0; i<n1; i++){
        a[i] = arr[lo+i];
    }
    for(int i=0; i<n2; i++){
        b[i] = arr[mid+i+1];
    }
    int i = 0, j = 0, k=lo;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k++] = a[i];
            i++;
        }else{
            arr[k++] = b[j];
            ans = ans + (n1-i);
            j++;
        }
    }
    while(i<n1){
        arr[k++] = a[i];
        i++;
    }
    while(j<n2){
        arr[k++] = b[j];
        j++;
    }
    return ans;
}

long long mergeSort(long long *arr, int lo, int hi){
    if(lo<hi){
        long long ans = 0;
        int mid = (lo+hi)/2;
        ans+=mergeSort(arr, lo, mid);
        ans+=mergeSort(arr, mid+1, hi);
        ans+=merge(arr, lo, mid, hi);
        return ans;
    }
    return 0;
}


long long getInversions(long long *arr, int n){
    
    int lo = 0, hi = n-1;
    return mergeSort(arr, lo, hi);

}