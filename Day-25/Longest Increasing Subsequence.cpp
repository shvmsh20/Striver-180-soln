//Recursive TLE
int util(int index, int prev, vector<int> &nums, int n){
        if(index==n){
            return 0;
        }
        if(prev==-1 || nums[index]>nums[prev]){
            return max(1+util(index+1, index, nums, n), util(index+1, prev, nums, n));
        }else{
            return util(index+1, prev, nums, n);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return util(0, -1, nums, n);
    }

//Memoization But TLE on leetcode (Top-down)
int util(int index, int prev, vector<int> &nums, int n, vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        if(prev==-1 || nums[index]>nums[prev]){
            return dp[index][prev+1] = max(1+util(index+1, index, nums, n, dp), util(index+1, prev, nums, n, dp));
        }else{
            return dp[index][prev+1] = util(index+1, prev, nums, n, dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return util(0, -1, nums, n, dp);
    }


//Bottom up    
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                if(j==-1 || nums[i]>nums[j]){
                    dp[i][j+1] = max(1+dp[i+1][i+1], dp[i+1][j+1]);
                }else{
                    dp[i][j+1] = dp[i+1][j+1];
                }
            }
        }
        return dp[0][-1+1];
    }

//Space optimized
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1);
        vector<int> curr(n+1);
        
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                if(j==-1 || nums[i]>nums[j]){
                    curr[j+1] = max(1+next[i+1], next[j+1]);
                }else{
                    curr[j+1] = next[j+1];
                }
            }
            next = curr;
        }
        return curr[0];
    }



//Simple Approach
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int mx=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
                mx = max(mx, dp[i]);
            }
        }
        return mx;
    }            

//In nlogn
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(int i=0; i<n; i++){
            if(dp.empty()){
                dp.push_back(nums[i]);
            }else if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }else{
                int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[index] = nums[i];
            }
        }
        return dp.size();
    }    