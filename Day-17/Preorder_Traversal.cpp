//Reursive
void util(TreeNode *root, vector<int> &v){
        if(root==nullptr){
            return;
        }
        v.push_back(root->val);
        util(root->left, v);
        util(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        util(root, v);
        return v;
    }

//Iterative
vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> v;
        TreeNode *curr = root;
        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                v.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }else{
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return v;
    }    