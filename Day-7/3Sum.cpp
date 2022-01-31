// T/C: O(n*n), S/C: O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0, left, right;
        for(i=0; i<n-2; i++){
            int target = 0-nums[i];
            left = i+1, right = n-1;
            while(left<right){
                if(nums[left]+nums[right]==target){
                    vector<int> v(3);
                    v[0] = nums[i];
                    v[1] = nums[left];
                    v[2] = nums[right];
                    res.push_back(v); 
                    while(left<right && nums[left]==v[1]){
                        left++;
                    }
                    while(left<right && nums[right]==v[2]){
                        right--;
                    }
                }else if(nums[left]+nums[right]>target){
                    right--;
                }else{
                    left++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }