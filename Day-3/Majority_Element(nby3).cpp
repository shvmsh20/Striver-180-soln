// T/C: O(n), S/C: O(n)
vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if(x.second>n/3){
                v.push_back(x.first);
            }
        }
        return v;
    }

// T/C: O(n), S/C: O(1)
vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int num1=-1, num2=-1, c1=0, c2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==num1){
                c1++;
            }else if(nums[i]==num2){
                c2++;
            }else if(c1==0){
                num1=nums[i];
                c1++;
            }else if(c2==0){
                num2=nums[i];
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        c1=0, c2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==num1){
                c1++;
            }else if(nums[i]==num2){
                c2++;
            }
        }
        if(c1>nums.size()/3){
            v.push_back(num1);
        }
        if(c2>nums.size()/3){
            v.push_back(num2);
        }
        return v;
    }    