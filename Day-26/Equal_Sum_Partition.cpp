//Recursive
bool solve(vector<int> &nums, int n, int sum){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(nums[n-1]>sum){
            return false;
        }else{
            return solve(nums, n-1, sum-nums[n-1]) || solve(nums, n-1, sum);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int n = nums.size();
        return solve(nums, n, sum/2);
    }

//Memo
int solve(vector<int> &nums, int n, int sum, vector<vector<int>> &dp){
        if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(nums[n-1]<=sum){
            return dp[n][sum] = (solve(nums, n-1, sum-nums[n-1], dp)==1) || (solve(nums, n-1, sum, dp)==1); 
        }else{
            return dp[n][sum] = solve(nums, n-1, sum, dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int n = nums.size();
        sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        int ans = solve(nums, n, sum, dp);
        cout << ans << endl;
        return ans;
    }

//Bottom up
bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int n = nums.size();
        sum = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1));
        for(int j=0; j<=n; j++){
            dp[j][0] = true;
        }
        for(int i=0; i<=sum; i++){
            dp[0][i] = false;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    } 

//Space optimization
bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int n = nums.size();
        sum = sum/2;
        vector<bool> prev(sum+1);
        vector<bool> curr(sum+1);
        for(int i=0; i<=sum; i++){
            prev[i] = false;
        }
        prev[0] = true;
        curr[0] = true;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j){
                    curr[j] = prev[j-nums[i-1]] || prev[j];
                }else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[sum];
    }