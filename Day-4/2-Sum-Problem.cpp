// T/C: O(n^2)
 vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), flag = 0;
        vector<int> v;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]+nums[j]==target){
                    v.push_back(i);
                    v.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        return v;
    }

// T/C: O(nlogn), S/C: O(n)
 vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v, temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        int i=0, j=nums.size()-1, n1, n2;
        while(i<j){
            if(temp[i]+temp[j]==target){
                n1 = temp[i];
                n2 = temp[j];
                break;
            }else if(temp[i]+temp[j]<target){
                i++;
            }else{
                j--;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==n1 || nums[i]==n2){
                v.push_back(i);
                if(v.size()==2){
                    break;
                }
            }
        }
        return v;
    }


// T/C: O(n), S/C: O(n)
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.count(target-nums[i])){
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                break;
            }else{
                m[nums[i]] = i;
            }
        }
        return v;
    } 