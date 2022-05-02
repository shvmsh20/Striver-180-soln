TreeNode* solve(vector<int>& preorder, int preS, int preE, vector<int>& inorder, int inS, int inE, unordered_map<int, int>&mp){
        if(preS>preE || inS>inE) return nullptr;
        TreeNode *node = new TreeNode(preorder[preS]);
        int index = mp[preorder[preS]];
        int left_num = index-inS;
        node->left = solve(preorder, preS+1, preS+left_num, inorder, inS, index-1, mp);
        node->right = solve(preorder, preS+left_num+1, preE, inorder, index+1, inE, mp);
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = preorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return solve(preorder, 0, n-1, inorder, 0, n-1, mp);
    }