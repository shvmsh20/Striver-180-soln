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