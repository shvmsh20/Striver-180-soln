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


long long merge(long long *arr, vector<long long> &temp, int lo, int mid, int hi){
   long long i=lo, j=mid+1, k=lo, count=0;
    while(i<=mid && j<=hi){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            count+= mid+1-i;
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=hi){
        temp[k++] = arr[j++];
    }
    for(int i=lo; i<=hi; i++){
        arr[i] = temp[i];
    }
    return count;
}

long long mergeSort(long long *arr, vector<long long> &temp, int l, int h){
    if(h>l){
        int mid = l+(h-l)/2;
        int invCount = mergeSort(arr, temp, l, mid);
        invCount+= mergeSort(arr, temp, mid+1, h);
        invCount+= merge(arr, temp, l, mid, h);
        return invCount;
    }
    return 0;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    vector<long long> temp(n);
    return mergeSort(arr, temp, 0, n-1);
}