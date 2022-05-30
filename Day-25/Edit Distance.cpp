//Recursive
int solve(string &s1, string &s2, int n, int m){
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        if(s1[n-1]==s2[m-1]){
            return solve(s1, s2, n-1, m-1);
        }else{
            int mn = min(1+solve(s1, s2, n, m-1), 1+solve(s1, s2, n-1, m));
            mn = min(mn, 1+solve(s1, s2, n-1, m-1));
            return mn;
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return solve(word1, word2, n, m);
    }

//Top down
int solve(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1]){
            return dp[n][m] = solve(s1, s2, n-1, m-1, dp);
        }else{
            int mn = min(1+solve(s1, s2, n, m-1, dp), 1+solve(s1, s2, n-1, m, dp));
            mn = min(mn, 1+solve(s1, s2, n-1, m-1, dp));
            return dp[n][m] = mn;
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(word1, word2, n, m, dp);
    }

//Bottom up
int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int i=0; i<=m; i++){
            dp[0][i] = i;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }

//Space optimized
int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> curr(m+1), prev(m+1);
        for(int i=0; i<=m; i++){
            prev[i] = i;
        }
        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = min(1+prev[j-1], min(1+curr[j-1], 1+prev[j]));
                }
            }
            prev = curr;
        }
        return prev[m];
    }    
    