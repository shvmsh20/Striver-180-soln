//T/C: O(n), S/C: O(1)
vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        vector<int> v;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                v.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==nullptr){
                    prev->right = curr;
                    v.push_back(curr->val);
                    curr = curr->left;
                }else{
                    prev->right = nullptr;
                    curr = curr->right;
                }
           }
            
        }
        return v;
    }