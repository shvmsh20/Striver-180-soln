// T/C: O(n), S/C: O(1)
int removeDuplicates(vector<int>& nums) {
        int curr = 0, n = nums.size();
        if(n==0){
            return 0;
        }
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[curr]){
                curr++;
                nums[curr] = nums[i];
            }
        }
        return curr+1;
    }