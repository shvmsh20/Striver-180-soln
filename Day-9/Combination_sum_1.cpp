void util(vector<int>& candidates, int target, int index, vector<int> &v,
              vector<vector<int>> &res, int sum){
        if(sum==target){
            res.push_back(v);
            return;
        }
        if(index==candidates.size() || sum>target){
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            sum+=candidates[i];
            v.push_back(candidates[i]);
            util(candidates, target, i, v, res, sum);
            sum-=candidates[i];
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        util(candidates, target, 0, v, res, 0);
        return res;
    }