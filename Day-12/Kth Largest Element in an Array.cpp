//T/C: O(k+(n-k)logk)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        for(int i=0; i<n && i<k; i++){
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