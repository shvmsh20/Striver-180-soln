//Bottom up
int wordBreak(string s, vector<string> &arr) {
        //code here
        int n = s.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                string t = s.substr(j, i-j+1);
                if(std::find(arr.begin(), arr.end(), t) != arr.end()){
                    if(j>0){
                        dp[i]+= dp[j-1];
                    }else{
                        dp[i]=1;
                    }
                }
            }
        }
        return dp[n-1]>0;
    }
//Memo
int solve(string s, int index, int n, unordered_set<string> &st, vector<int> &dp){
        if(index==n){
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=index; i<n; i++){
            string temp = s.substr(index, i-index+1);
            if(st.find(temp)!=st.end() && solve(s, i+1, n, st, dp)){
                return dp[index] = 1;
            } 
        }
        return dp[index] = 0;
    }
    int wordBreak(string s, vector<string> &arr) {
        //code here
        int n = s.size();
        unordered_set<string> st;
        for(auto x: arr){
            st.insert(x);
        }
        vector<int> dp(n, -1);
        return solve(s, 0, n, st, dp);
    }    


//Tablulatar
//GFG TLE O(N^3)
int wordBreak(string s, vector<string> &arr) {
        //code here
        int n = s.size();
        unordered_set<string> st;
        for(auto x: arr){
            st.insert(x);
        }
        vector<vector<bool>> dp(n, vector<bool> (n));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++, j++){
                string temp = s.substr(i, g+1);
                if(st.find(temp)!=st.end()){
                    dp[i][j] = true;
                }else{
                    bool flag = false;
                    for(int k=i; k<=j; k++){
                        if(dp[i][k] && dp[k+1][j]){
                            flag = true;
                            break;
                        }
                    }
                    dp[i][j] = flag;
                }
            }
        }
        return dp[0][n-1];
    }
