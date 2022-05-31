int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int i=1; i<m; i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }

//Recursive
int solve(int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return INT_MAX;
        }
        int up = solve(i-1, j, grid);
        int left = solve(i, j-1, grid);
        return grid[i][j]+min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(n-1, m-1, grid);
    }


//Memo
int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = solve(i-1, j, grid, dp);
        int left = solve(i, j-1, grid, dp);
        return dp[i][j] =  grid[i][j]+min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, grid, dp);
    }

//Bottom up
int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int up = grid[i][j];
                int left = grid[i][j];
                if(i>0){
                    up+= dp[i-1][j];
                }else{
                    up = INT_MAX;
                }
                
                if(j>0){
                    left+= dp[i][j-1];
                }else{
                    left = INT_MAX;
                }
                dp[i][j] = min(up, left);
            }
        }
        return dp[n-1][m-1];
    }            