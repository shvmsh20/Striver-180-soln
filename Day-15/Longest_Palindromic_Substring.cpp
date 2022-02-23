//T/C: O(n^2), S/C: O(n^2)
string longestPalindrome(string s) {
        int n = s.length(), p, q;
        string ans;
        vector<vector<int>> dp(n, vector<int> (n));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; j++, i++){
                if(g==0){
                    dp[i][j]=1;
                }else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j]==1){
                    p = i;
                    q = j;
                }
            }
        }
        return s.substr(p, q-p+1);
    }