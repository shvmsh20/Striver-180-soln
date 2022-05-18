int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            TreeNode *curr = st.top();
            st.pop();
            if(k==1){
                return curr->val;
            }
            k--;
            root = curr->right;
        }
        return -1;
    }