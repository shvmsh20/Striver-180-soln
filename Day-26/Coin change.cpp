//Recursive
int solve(vector<int>& coins, int n, int amount){
        if(amount==0){
            return 0;
        }
        if(n==0){
            return INT_MAX-1;
        }
        if(coins[n-1]<=amount){
            return min(1+solve(coins, n, amount-coins[n-1]), solve(coins, n-1, amount));
        }else{
            return solve(coins, n-1, amount); 
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int res = solve(coins, n, amount);
        return res==INT_MAX-1?-1:res;
    }

//Memo
int solve(vector<int>& coins, int n, int amount, vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(n==0){
            return INT_MAX-1;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1]<=amount){
            return dp[n][amount] = min(1+solve(coins, n, amount-coins[n-1], dp), solve(coins, n-1, amount, dp));
        }else{
            return dp[n][amount] = solve(coins, n-1, amount, dp); 
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();       
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int res = solve(coins, n, amount, dp);
        return res==INT_MAX-1?-1:res;
    }

//Bottom up
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();       
        vector<vector<int>> dp(n+1, vector<int> (amount+1));
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=amount; j++){
            dp[0][j] = INT_MAX-1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];
    }    