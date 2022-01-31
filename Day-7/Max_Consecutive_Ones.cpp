//T/C: O(n), S/C: O(1)
int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, curr=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                curr++;
                res = max(res, curr);
            }else{
                curr=0;
            }
        }
        return res;
    }