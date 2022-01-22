int majorityElement(vector<int>& nums) {
        int maj=nums[0], count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==maj){
                count++;
            }else{
                count--;
                if(count==0){
                    maj=nums[i];
                    count=1;
                }
            }
        }
        return maj;
    }