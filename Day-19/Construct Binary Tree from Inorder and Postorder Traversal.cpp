TreeNode* solve(vector<int>& inorder,int inS, int inE, vector<int>& postorder, int poS, int poE, unordered_map<int, int> &mp){
        if(inS>inE || poS>poE) return nullptr;
        TreeNode *root = new TreeNode(postorder[poE]);
        int rootIndex = mp[postorder[poE]];
        int left_num = rootIndex - inS;
        root->left = solve(inorder, inS, rootIndex-1, postorder, poS, poS+left_num-1, mp);
        root->right = solve(inorder, rootIndex+1, inE, postorder, poS+left_num, poE-1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return solve(inorder, 0, n-1, postorder, 0, n-1, mp);
    }