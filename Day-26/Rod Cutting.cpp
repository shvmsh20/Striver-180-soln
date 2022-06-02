//Recursive
int solve(int price[], int n, int length){
        if(length==0){
            return 0;
        }
        if(n==0){
            return INT_MIN;
        }
        if(n<=length){
            return max(price[n-1]+solve(price, n, length-n), solve(price, n-1, length));
        }else{
            return solve(price, n-1, length);
        }
    }
    int cutRod(int price[], int n) {
        //code here
        return solve(price, n, n);
        
    }

//Memo
int solve(int price[], int n, int length, vector<vector<int>> &dp){
        if(length==0){
            return 0;
        }
        if(n==0){
            return INT_MIN;
        }
        if(dp[n][length]!=-1){
            return dp[n][length];
        }
        if(n<=length){
            return dp[n][length] = max(price[n-1]+solve(price, n, length-n, dp), solve(price, n-1, length, dp));
        }else{
            return dp[n][length] = solve(price, n-1, length, dp);
        }
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(price, n, n, dp);
        
    }

// Bottom up
int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        int length=n;
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=length; j++){
            dp[0][j] = INT_MIN;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=length; j++){
                if(i<=j){
                    dp[i][j] = max(price[i-1]+dp[i][j-i], dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][length];
        
    }  