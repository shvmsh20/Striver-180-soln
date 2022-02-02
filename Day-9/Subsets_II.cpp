 //T/C: O(pow(2,n)*log(pow(2,n))), S/C: O(pow(2,n))
 void util(vector<int>& nums, int index, vector<int> v, set<vector<int>> &res){
        if(index==nums.size()){
            sort(v.begin(), v.end());
            res.insert(v);
            return;
        }
        util(nums, index+1, v, res);
        v.push_back(nums[index]);
        util(nums, index+1, v, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> v;
        util(nums, 0, v, res);
        vector<vector<int>> ans;
        for(auto x:res){
            ans.push_back(x);
        }
        return ans;
    }
//optimal
//T/C: O(pow(2,n)*n), S/C:(pow(2,n)*k)
void util(vector<int>& nums, int index, int n, vector<int> &v, vector<vector<int>> &res){
        res.push_back(v);
        for(int i=index; i<n; i++){
            if(i==index || (i!=index && nums[i]!=nums[i-1])){
                v.push_back(nums[i]); 
                util(nums, i+1, n, v, res);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(), nums.end());
        util(nums, 0, n, v, res);
        return res;
    }