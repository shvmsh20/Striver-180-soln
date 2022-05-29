int maxProduct(vector<int>& nums) {
        int currMin=1, currMax=1;
        int res=INT_MIN;
        for(int x: nums){
            res = max(res, x);
        }
        for(int x: nums){
            if(x==0){
                currMin = 1;
                currMax = 1;
            }else{
                int temp = currMax;
                currMax = max(currMin*x, max(currMax*x, x));
                currMin = min(currMin*x, min(temp*x, x));
                res = max(res, currMax);
            }
        }
        return res;
    }
// M-2
int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int cpro=1;
        for(int i=0; i<nums.size(); i++){
            cpro*=nums[i];
            res = max(res, cpro);
            if(nums[i]==0){
                cpro = 1;
                continue;
            }
        }
        cpro=1;
        for(int i=nums.size()-1; i>=0; i--){
            cpro*=nums[i];
            res = max(res, cpro);
            if(nums[i]==0){
                cpro = 1;
                continue;
            }
        }
        return res;
    }

// M-1 modified  
int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int cmax = nums[0], cmin = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<0){
                swap(cmax, cmin);  
            }
            cmax = max(nums[i], cmax*nums[i]);
            cmin = min(nums[i], cmin*nums[i]);
            res = max(res, cmax);
        }
        return res;
    }  