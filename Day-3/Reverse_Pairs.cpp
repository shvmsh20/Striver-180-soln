// T/C: O(nlogn), S/C: O(n)
void merge(vector<int> &nums, int lo, int mid, int hi, int &count){
        int n1 = mid-lo+1, n2 = hi-mid, i, j, k;
        int a[n1], b[n2];
        for(i=0; i<n1; i++){
            a[i] = nums[lo+i];
        }
        for(j=0; j<n2; j++){
            b[j] = nums[mid+j+1];
        }
        j = 0;
        for(i=0; i<n1; i++){
            while(j<n2 && a[i] > 2LL * b[j]){
                j++;
            }
            count+=j;
        }
        i = 0, j = 0, k=lo;
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                nums[k++] = a[i++];
            }else{
                nums[k++] = b[j++];
            }
        }
        while(i<n1){
            nums[k++] = a[i++];
        }
        while(j<n2){
            nums[k++] = b[j++];
        }
    }
    void mergeSort(vector<int> &nums, int lo, int hi, int &count){
        if(lo>=hi){
            return;
        }
        int mid = (lo+hi)/2;
        mergeSort(nums, lo, mid, count);
        mergeSort(nums, mid+1, hi, count);
        merge(nums, lo, mid, hi, count);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        mergeSort(nums, 0, n-1, count);
        return count;
    }


//Different Implementation
    int merge(vector<int>& nums, vector<int> &temp, int lo, int mid, int hi){
        int i=lo, j=mid+1, k=lo;
        int count=0;
        for(int i=lo; i<=mid; i++){
            while(j<=hi && nums[i]>2LL*nums[j]){
                j++;
            }
            count+= j-(mid+1);
        }
        j=mid+1;
        while(i<=mid && j<=hi){
            if(nums[i]<=nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        while(j<=hi){
            temp[k++] = nums[j++];
        }
        for(int i=lo; i<=hi; i++){
            nums[i] = temp[i];
        }
        return count;
    }
    int mergeSort(vector<int>& nums, vector<int> &temp, int lo, int hi){
        if(hi>lo){
            int mid = lo+(hi-lo)/2;
            int count=0;
            count+= mergeSort(nums, temp, lo, mid);
            count+= mergeSort(nums, temp, mid+1, hi);
            count+= merge(nums, temp, lo, mid, hi);
            return count;  
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums, temp, 0, n-1);
    }