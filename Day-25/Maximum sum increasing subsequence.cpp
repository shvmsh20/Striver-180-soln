//Recursive
int solve(int currIndex, int prevIndex, int arr[], int n){
	    if(currIndex==n){
	        return 0;
	    }
	    int sum = solve(currIndex+1, prevIndex, arr, n);
	    if(prevIndex==-1 || arr[currIndex]>arr[prevIndex]){
	        sum = max(sum, arr[currIndex]+solve(currIndex+1, currIndex, arr, n));
	    }
	    return sum;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    return solve(0, -1, arr, n);
	}  

//Memo
int solve(int currIndex, int prevIndex, int arr[], int n, vector<vector<int>> &dp){
	    if(currIndex==n){
	        return 0;
	    }
	    if(dp[currIndex][prevIndex+1]!=-1){
	        return dp[currIndex][prevIndex+1];
	    }
	    int sum = solve(currIndex+1, prevIndex, arr, n, dp);
	    if(prevIndex==-1 || arr[currIndex]>arr[prevIndex]){
	        sum = max(sum, arr[currIndex]+solve(currIndex+1, currIndex, arr, n, dp));
	    }
	    return dp[currIndex][prevIndex+1] = sum;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n, vector<int> (n+1, -1));
	    return solve(0, -1, arr, n, dp);
	}  

//Bottom up
int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
	    for(int i=n-1; i>=0; i--){
	        for(int j=i-1; j>=-1; j--){
	            if(j==-1 || arr[i]>arr[j]){
	                dp[i][j+1] = max(dp[i+1][j+1], arr[i]+dp[i+1][i+1]);
	            }else{
	                dp[i][j+1] = dp[i+1][j+1];
	            }
	        }
	    }
	    return dp[0][0];
	    
	} 

//M-2
int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n);
	    for(int i=0; i<n; i++){
	        dp[i] = arr[i];
	    }
	    int res = arr[0];
	    for(int i=1; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(arr[i]>arr[j]){
	                dp[i] = max(dp[i], arr[i]+dp[j]);
	            }
	        }
	        res = max(res, dp[i]);
	    }
	    return res;
	}         