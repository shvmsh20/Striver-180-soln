TreeNode* solve(vector<int>& preorder, int &index, int ur){
        if(index==preorder.size() || preorder[index]>ur){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[index]);
        index++;
        node->left = solve(preorder, index, node->val);
        node->right = solve(preorder, index, ur);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ur = INT_MAX;
        int index=0;
        return solve(preorder, index, ur);
    }