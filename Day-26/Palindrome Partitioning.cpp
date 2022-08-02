//Aditya verma
bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s, int l, int h, vector<vector<int>> &dp){
        if(l>=h || isPalindrome(s, l, h)){
            return 0;
        }
        if(dp[l][h]!=-1){
            return dp[l][h];
        }
        int mn = INT_MAX;
        for(int k=l; k<h; k++){
            int left;
            if(dp[l][k]==-1){
                dp[l][k] = solve(s, l, k, dp);
                left = dp[l][k];
            }else{
                left = dp[l][k];
            }
            int right;
            if(dp[k+1][h]==-1){
                dp[k+1][h] = solve(s, k+1, h, dp);
                right = dp[k+1][h];
            }else{
                right = dp[k+1][h];
            }
            int t = left+right+1;
            mn = min(mn, t);
        }
        return dp[l][h] = mn;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(str, 0, n-1, dp);
    }



//Memo
bool isPal(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int n, string &s, vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mn = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPal(i, j, s)){
                int t = solve(j+1, n, s, dp);
                mn = min(mn, t);
            }
        }
        return dp[i] = mn+1;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n, -1);
        return solve(0, n, str, dp)-1;
    }


//Tabular
bool isPal(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n+1, 0);
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
            int mn = INT_MAX;
            for(int j=i; j<n; j++){
                if(isPal(i, j, str)){
                    int t = 1+dp[j+1];
                    mn = min(mn, t);
                }
            }
            dp[i] = mn;
        }
        return dp[0]-1;
    }    
