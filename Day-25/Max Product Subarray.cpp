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