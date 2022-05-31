//Recursive
int solve(int arr[], int i, int j){
        if(i>=j){
            return 0;
        }
        int mn = INT_MAX;
        for(int k=i; k<=j-1; k++){
            int left = solve(arr, i, k);
            int right = solve(arr, k+1, j);
            int temp = left+right+(arr[i-1]*arr[k]*arr[j]);
            mn = min(mn, temp);
        }
        return mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr, 1, N-1);
    }

//Memo
int solve(int arr[], int i, int j, vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i; k<=j-1; k++){
            int left;
            if(dp[i][k]!=-1){
                left = dp[i][k];
            }
            else {
                left = solve(arr, i, k, dp);
            }
            int right;
            if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }else{
                right = solve(arr, k+1, j, dp);
            }
            int temp = left+right+(arr[i-1]*arr[k]*arr[j]);
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (N, -1));
        return solve(arr, 1, N-1, dp);
    }

//Another i, j combination
int solve(int arr[], int i, int j, vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i+1; k<=j; k++){
            int left;
            if(dp[i][k-1]!=-1){
                left = dp[i][k-1];
            }
            else {
                left = solve(arr, i, k-1, dp);
            }
            int right;
            if(dp[k][j]!=-1){
                right = dp[k][j];
            }else{
                right = solve(arr, k, j, dp);
            }
            int temp = left+right+(arr[i-1]*arr[k-1]*arr[j]);
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (N, -1));
        return solve(arr, 1, N-1, dp);
    }        