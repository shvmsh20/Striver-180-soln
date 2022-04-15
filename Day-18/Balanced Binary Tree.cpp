int solve(TreeNode* curr){
        if(curr==nullptr){
            return 0;
        }
        int lh = solve(curr->left);
        int rh = solve(curr->right);
        if(lh==-1){
            return -1;
        }
        if(rh==-1){
            return -1;
        }
        if(abs(lh-rh)>1){
            return -1;
        }
        return max(lh, rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(solve(root)==-1){
            return false;
        }
        return true;
    }