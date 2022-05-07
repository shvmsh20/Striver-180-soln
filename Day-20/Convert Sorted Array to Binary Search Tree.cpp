TreeNode *solve(vector<int>& nums, int s, int e){
        if(s>e){
            return nullptr;
        }
        int mid = (s+e)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = solve(nums, s, mid-1);
        node->right = solve(nums, mid+1, e);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n-1);
    }