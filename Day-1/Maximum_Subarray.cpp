int maxSubArray(vector<int>& nums) {
        int maxSoFar = INT_MIN, maxCurr = 0;
        for(int i=0; i<nums.size(); i++){
            maxCurr+= nums[i];
            maxSoFar = max(maxSoFar, maxCurr);
            if(maxCurr<0){
                maxCurr = 0;
            }
        }
        return maxSoFar;
    }