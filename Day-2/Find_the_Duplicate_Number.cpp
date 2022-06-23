M-1 Sort 
M-2 Hashing
M-3 tortoise method

int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        //find collision point
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        //find loop starting point or duplicate number
        slow = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }