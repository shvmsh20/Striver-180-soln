int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> mp;
        int curr_sum=0, mx=0;
        for(int i=0; i<n; i++){
            curr_sum+= A[i];
            if(curr_sum==0){
                mx = i+1;
            }else if(mp.count(curr_sum)){
                mx = max(mx, i-mp[curr_sum]);
            }else{
                mp[curr_sum] = i;
            }
        }
        return mx;
    }