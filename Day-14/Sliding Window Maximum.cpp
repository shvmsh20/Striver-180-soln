//Using priority_queue
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<k-1; i++){
            pq.push({nums[i], i});
        }
        vector<int> res;
        for(int i=k-1; i<nums.size(); i++){
            pq.push({nums[i], i});
            while(pq.top().second<=i-k){
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        return res;
    }

//Using deque
//T/C: O(N), S/C: O(k)          Monotonic queue, decreasing order eg. 3 2 1
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> res;
        res.push_back(nums[dq.front()]);
        for(int i=k; i<nums.size(); i++){
            if(dq.front()==i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }