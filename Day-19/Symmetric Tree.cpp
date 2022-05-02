bool solve(TreeNode* t1, TreeNode* t2){
        if(t1==nullptr || t2==nullptr){
            return t1==t2;
        }
        if(t1->val!=t2->val){
            return false;
        }
        if(solve(t1->left, t2->right)==false){
            return false;
        }
        if(solve(t1->right, t2->left)==false){
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }