//M-1
void solve(TreeNode* root, TreeNode* &prev){
        if(root==nullptr){
            return;
        }
        solve(root->right, prev);
        solve(root->left, prev);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    void flatten(TreeNode* root) {
        TreeNode *prev = nullptr;
        solve(root, prev);
    }

//M-2
void flatten(TreeNode* root) {
        stack<TreeNode* > st;
        if(root==nullptr){
            return;
        }
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
               curr->right = st.top(); 
            }
            
            curr->left = nullptr;
        }

//M-3
void flatten(TreeNode* root) {
        TreeNode* curr = root, * prev;
        while(curr!=nullptr){
            if(curr->left){
                prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right; 
        }
    }            