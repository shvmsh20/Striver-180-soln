//T/C: O(3n)
 int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int curr=0, mx=0; 
        for(int i=0; i<n; i++){
            if(s.find(nums[i]-1)==s.end()){
                int curr=1;
                while(s.find(nums[i]+curr)!=s.end()){
                    curr++;
                }
                mx = max(curr, mx);
            }
        }
        return mx;
    }