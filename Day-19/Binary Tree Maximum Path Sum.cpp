int ans = INT_MIN;
    int solve(TreeNode* curr){
        if(curr==nullptr){
            return 0;
        }
        int l = max(0, solve(curr->left));
        int r = max(0, solve(curr->right));
        ans = max(ans, curr->val+l+r);
        return curr->val+max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }