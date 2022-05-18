stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        Lefttree(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            Lefttree(top->right);  
        return top->val;
    }
    
    bool hasNext() {
         return st.empty() ? false : true;
    }
    void Lefttree(TreeNode* root)
    {
        TreeNode* p = root;
        while (p)
        {
            st.push(p);
            p = p->left;
        }
    }