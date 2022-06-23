//Accepted
//T/C: O(n^3)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int lo = j+1;
                int hi = n-1;
                if((long long)target-nums[i]<INT_MIN){
                    break;;
                }
                long long temp = target-nums[i];
                if((long long)temp-nums[j]<INT_MIN){
                    break;
                }
                temp-= nums[j];
                vector<int> v(4);
                while(lo<hi){
                    if(nums[lo]+nums[hi]==temp){
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[lo];
                        v[3] = nums[hi];
                        res.push_back(v);
                        while(lo<hi && nums[lo]==nums[lo+1]){
                            lo++;
                        }
                        while(lo<hi && nums[hi]==nums[hi-1]){
                            hi--;
                        }
                        lo++;
                        hi--;
                    }else if(nums[lo]+nums[hi]<temp){
                        lo++;
                    }else{
                        hi--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
//Not Accepted now
vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }