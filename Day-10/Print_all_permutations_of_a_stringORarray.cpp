//T/C:(n!*n), S/C:O(n)+O(n)
void util(vector<int>& nums, int freq[], vector<int> &ds, vector<vector<int>> &res){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(freq[i]==0){
                freq[i]=1;
                ds.push_back(nums[i]);
                util(nums, freq, ds, res);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++){
            freq[i]=0;
        }
        util(nums, freq, ds, res);
        return res;
    }

//T/C:O(n!*n), S/C:O(1)
void util(vector<int>& nums, int ind, vector<vector<int>> &res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            util(nums, ind+1, res);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        util(nums, 0, res);
        return res;
    }    