//Bottom up (Pepcoding)
int wordBreak(string s, vector<string> &arr) {
        //code here
        int n = s.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                string t = s.substr(j, i-j+1);
                if(std::find(arr.begin(), arr.end(), t) != arr.end()){
                    if(j>0){
                        //Take mod by 1e9+7 to avoid overflow
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

//Tech dose
//Tablulatar
//GFG TLE O(N^3)
bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string, int> mp;
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]]++;
        }
        vector<vector<bool>> dp(n+1, vector<bool> (n+1));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++,j++){
                string t = s.substr(i, j-i+1);
                if(mp.find(t)!=mp.end()){
                    dp[i][j] = true;
                }else{
                    bool flag = false;
                    for(int k=i; k<j; k++){
                        if(dp[i][k] && dp[k+1][j]){
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[0][n-1];
    }

 //Neetcode
//O(n*m*n)
bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<wordDict.size(); j++){
                if(i+wordDict[j].size()<=n){
                    string temp = s.substr(i, wordDict[j].size());
                    if(temp==wordDict[j]){
                        dp[i] = dp[i+wordDict[j].size()];
                    }
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }