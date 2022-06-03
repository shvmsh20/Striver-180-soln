static bool cmp(Job j1, Job j2){
        return j1.profit>j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, cmp);
        int mn = INT_MIN;
        for(int i=0; i<n; i++){
            int t = arr[i].dead;
            mn = max(mn, t);
        }
        vector<int> v(mn+1, -1);
        int res=0, count=0;
        for(int i=0; i<n; i++){
            int deadline = arr[i].dead;
            while(deadline>=1){
                if(v[deadline]==-1){
                    v[deadline] = arr[i].id;
                    res+= arr[i].profit;
                    count++;
                    
                    break;
                }
                deadline--;
            }
        }
        vector<int> ans(2);
        ans[0] = count;
        ans[1] = res;
        return ans;
    } 