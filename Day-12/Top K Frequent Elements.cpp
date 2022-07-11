//T/C: O(n) + O(n) + O(klogn)
    //Map   //Heapify // Removing top k
vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pi, vector<pi>, cmp> pq;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;    
        }
        for(auto x: mp){
            pq.push({x.first, x.second});
        }
        while(!pq.empty() && k--){
            auto x = pq.top();
            pq.pop();
            res.push_back(x.first);
        }
        return res;
    }
//T/C: O(n), S/C: O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;    
        }
        vector<vector<int>> buckets(n+1);
        for(auto x: mp){
            int freq = x.second;
            int num = x.first;
            buckets[freq].push_back(num);
        }
        
        for(int i=n; i>=0; i--){
            if(buckets[i].size()){
                for(int j=0; j<buckets[i].size() && res.size()<k; j++){
                    res.push_back(buckets[i][j]);
                }
            }
            if(res.size()==k){
                break;
            }
        }
        
        return res;
    }        