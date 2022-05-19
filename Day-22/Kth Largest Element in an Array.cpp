//M-1 Using heap
//T/C: O(k+ (n-k)logk)
//S/C: O(k)
int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        for(int i=k; i<n; i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

//M-2 Using quickSelect
//T/C: Avg O(n) n+(n/2)+(n/4)..., Worst case O(n^2) deleting 1 element in each iteration
//S/C: O(1)    
int quickSelect(vector<int> &nums, int l, int h, int k){
        int p=l, pivot = nums[h];
        for(int i=l; i<h; i++){
            if(nums[i]<=pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[h], nums[p]);
        if(p==k){
            return nums[p];
        }else if(p<k){
            return quickSelect(nums, p+1, h, k);
        }else if(p>k){
            return quickSelect(nums, l, p-1, k);
        }
        return 0;
    }
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        return quickSelect(nums, 0, nums.size()-1, k);
    }