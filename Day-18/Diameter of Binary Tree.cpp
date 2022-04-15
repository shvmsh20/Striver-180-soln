int ans = INT_MIN;
    int solve(TreeNode *curr){
        if(curr==nullptr){
            return 0;
        }
        int l = solve(curr->left);
        int h = solve(curr->right);
        int temp = max(l,h);
        ans = max(ans, l+h);
        return 1+temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }