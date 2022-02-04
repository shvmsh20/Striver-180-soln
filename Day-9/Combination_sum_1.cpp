//T/C: O(pow(2,t)*k)
void util(vector<int>& candidates, int target, int index, vector<int> &v,
          vector<vector<int>> &res){
        if(index==candidates.size()){
            if(target==0){
                res.push_back(v);
            }
            return;
        }
        if(target>=candidates[index]){
            v.push_back(candidates[index]);
            util(candidates, target-candidates[index], index, v, res);
            v.pop_back();
        }
        util(candidates, target, index+1, v, res);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> res;
        util(candidates, target, 0, v, res);
        return res;
    }

//OR
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