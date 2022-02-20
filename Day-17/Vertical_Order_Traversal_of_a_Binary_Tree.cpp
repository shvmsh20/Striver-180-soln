//T/C: O(nlogn), S/C: O(n)
vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            m[x][y].insert(it.first->val);
            if(it.first->left){
                q.push({it.first->left, {x-1, y+1}});
            }
            if(it.first->right){
                q.push({it.first->right, {x+1, y+1}});
            }  
        }
        for(auto p: m){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(),q.second.begin(), q.second.end());
            }
            v.push_back(col);
        }
        return v;
        
    }