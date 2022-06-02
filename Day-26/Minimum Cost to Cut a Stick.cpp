//Recursive
int solve(int i, int j, vector<int> &cuts){
        if(i>j){
            return 0;
        }
        int mn = INT_MAX;
        for(int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts) + solve(k+1, j, cuts);
            mn = min(mn, cost);
        }
        return mn;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        return solve(1, size-2, cuts);
    }

//Memo
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            mn = min(mn, cost);
        }
        return dp[i][j] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int> (size, -1));
        return solve(1, size-2, cuts, dp);
    }

//Bottom up

int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size()-2;
        vector<vector<int>> dp(size+2, vector<int> (size+2, -0));
        for(int i=size; i>=1; i--){
            for(int j=1; j<=size; j++){
                if(i>j){
                    continue;
                }
                int mn = INT_MAX;
                for(int k=i; k<=j; k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mn = min(mn, cost);
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][size];
    }            