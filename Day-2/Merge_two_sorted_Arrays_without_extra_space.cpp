//Soln1: LeetCode
// T/C: O(n*m)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j;
        if(n==0) return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        while(i<m){
            if(nums2[0]<nums1[i]){
                swap(nums1[i], nums2[0]);
                int temp = nums2[0];
                // place nums2[0] in its correct position
                for(j=1; j<n && nums2[j]<temp; j++){
                    nums2[j-1] = nums2[j];
                }
                nums2[j-1] = temp;  
            }
            i++;
        }
        for(int i=0; i<n;i++){
            nums1[i+m] = nums2[i];
        }
    } 

//Soln2: GFG
// T/C: O(n*logn)
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap = ceil((n+m)/2.0), i, j;
            while(gap>0){
                i=0;
                j=gap;
                while(j<n+m){
                    if(j<n && arr1[i]>arr1[j]){
                        swap(arr1[i], arr1[j]);
                    }else if(i<n && j>=n && arr1[i]>arr2[j-n]){
                        swap(arr1[i], arr2[j-n]);
                    }else if(i>=n && j>=n && arr2[i-n]>arr2[j-n]){
                        swap(arr2[i-n], arr2[j-n]);
                    }
                    i++;
                    j++;
                }
                if(gap==1){
                    gap=0;
                }else{
                    gap = ceil(gap/2.0);
                } 
            }
        }

//Soln3: GFG
// T/C: O(n + m + nlogn + mlogm)        
void merge(long long arr1[], long long arr2[], int n, int m) 
        {  
            int i = n-1;
            int j=0;
            while(i>=0 && j<m){
                if(arr1[i]>arr2[j]){
                    swap(arr1[i], arr2[j]);
                    i--;
                    j++;
                }else{
                   
                    break;
                    
                }
            }
             sort(arr1, arr1+n);
             sort(arr2, arr2+m);
     } 