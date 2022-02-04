// T/C:O(pow(2,n)*k), S/C: O(x*K)
void util(vector<int>& candidates, int target, int index, vector<int> &v,
              vector<vector<int>> &res){
        if(target==0){
            res.push_back(v);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i!= index && candidates[i-1]==candidates[i]){
                continue;
            }
            if(target<candidates[i]){
                break;
            }
            v.push_back(candidates[i]);
            util(candidates, target-candidates[i], i+1, v, res);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        util(candidates, target, 0, v, res);
        return res;
    }