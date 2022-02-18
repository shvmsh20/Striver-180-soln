//Recursive
void util(TreeNode *root, vector<int> &v){
        if(root==nullptr){
            return;
        }
        
        util(root->left, v);
        util(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        util(root, v);
        return v;
    }

//Iterative
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==nullptr){
            return v;
        }
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode *curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left){
                st1.push(curr->left);
            }
            if(curr->right){
                st1.push(curr->right);
            }
        }
        while(!st2.empty()){
            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;
        
    }