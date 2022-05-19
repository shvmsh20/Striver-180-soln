int K;
    priority_queue <int, vector<int>, greater<int>> hp;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0; i<nums.size() && i<k; i++){
            hp.push(nums[i]);
        }
        for(int i=k; i<nums.size(); i++){
            if(nums[i]>hp.top()){
                hp.pop();
                hp.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(hp.size()<K){
            hp.push(val);
        }
        else if(val>hp.top()){
            hp.pop();
            hp.push(val);
        }
        return hp.top();
    }