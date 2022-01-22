//Recursive
int util(int i, int j, int m, int n){
        if(i==m || j==n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        return util(i+1, j, m, n)+util(i, j+1, m, n);
    }
    int uniquePaths(int m, int n) {
        int i=0, j=0;
        return util(i, j, m, n);
    }

//DP
int util(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i==m || j==n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=util(i+1, j, m, n, dp)+util(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        int i=0, j=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return util(i, j, m, n, dp);
    }

//Using maths
int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res = 1.0;
        for(int i=1; i<=r; i++){
            res = res *(N-r+i)/i;
        }
        return int(res);
    }        