//Recursive
int util(string s1, string s2, int i, int j, int n1, int n2){
        if(i==n1 || j==n2){
            return 0;
        }
        if(s1[i]==s2[j]){
            return 1+util(s1, s2, i+1, j+1, n1, n2);
        }
        return max(util(s1, s2, i+1, j, n1, n2), util(s1, s2, i, j+1, n1, n2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        return util(text1, text2, 0, 0, n1, n2);
    }

//Memoization (Top-down)
int util(string &s1, string &s2, int i, int j, int n1, int n2, vector<vector<int>> &dp){
        if(i==n1 || j==n2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+util(s1, s2, i+1, j+1, n1, n2, dp);
        }
        int l;
        if(i+1<n1 && dp[i+1][j]!=-1){
            l = dp[i+1][j];
        }else{
            l = util(s1, s2, i+1, j, n1, n2, dp);
        }
        int r;
        if(j+1<n2 && dp[i][j+1]!=-1){
            r = dp[i][j+1];
        }else{
            r = util(s1, s2, i, j+1, n1, n2, dp);
        }
        return dp[i][j] = max(l, r);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return util(text1, text2, 0, 0, n1, n2, dp);
    }

//Tabular (Bottom up)
int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
