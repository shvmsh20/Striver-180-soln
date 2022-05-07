bool solve(TreeNode *root, long long l, long long r){
        if(root==nullptr){
            return true;
        }
        if(!(root->val>l && root->val<r)){
            return false;
        }
        if(solve(root->left, l, root->val)==false){
            return false;
        }
        return solve(root->right, root->val, r);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }