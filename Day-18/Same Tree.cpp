bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){
            return true;
        }
        if((p==nullptr && q!=nullptr) || (p!=nullptr && q==nullptr)){
            return false;
        }
        if((p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
            return true;
        }else{
            return false;
        }
    }