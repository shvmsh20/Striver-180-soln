vector<int> solve(TreeNode* root, int &res){
        if(root==nullptr){
            return {0, INT_MIN, INT_MAX};
        }
        //{sum of nodes of BST, largest, smallest}
        auto left = solve(root->left, res);
        auto right = solve(root->right, res);
        int low = left[1];
        int high = right[2];
        int value;
        if(root->val>low && root->val<high){
            value = left[0]+right[0]+root->val;
            res = max(res, value);
            return {value, max(root->val, right[1]), min(root->val, left[2])};
        }else{
            value = max(left[0], right[0]);
            return {value, INT_MAX, INT_MIN};
        }
        
    }
    int maxSumBST(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res<0?0:res;
    }