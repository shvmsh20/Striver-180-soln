//Recursive
void util(TreeNode *root, vector<int> &v){
        if(root==nullptr){
            return;
        }
        util(root->left, v);
        v.push_back(root->val);
        util(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        util(root, v);
        return v;
    }

//Iterative
 vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode* > st;
        TreeNode *curr = root;
        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode *popped = st.top();
                st.pop();
                v.push_back(popped->val);
                curr = popped->right;
            }
        }
        return v;
    }    