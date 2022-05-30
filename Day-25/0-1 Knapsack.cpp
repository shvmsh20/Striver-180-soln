//Recursive
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    if(n==0 || w==0){
        return 0;
    }
    if(weights[n-1]>w){
        return maxProfit(values, weights, n-1, w);
    }else{
        return max(maxProfit(values, weights, n-1, w), values[n-1]+maxProfit(values, weights, n-1, w-weights[n-1]));
    }
    
}

//Top down
int solve(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>> &dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(w<weights[n-1]){
        return dp[n][w] = solve(values, weights, n-1, w, dp);
    }else{
        return dp[n][w] = max(solve(values, weights, n-1, w, dp), values[n-1]+solve(values, weights, n-1, w-weights[n-1], dp));
    }
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n+1, vector<int> (w+1, -1));
    return solve(values, weights, n, w, dp);
    
}

//Bottom up
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(weights[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], values[i-1]+dp[i-1][j-weights[i-1]]);
            }
        }
    }
    return dp[n][w];
}