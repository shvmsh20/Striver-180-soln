//Use long long as some test cases gives integer overflow
//T/C: O(n), S/C:O(n)
long long widthOfBinaryTree(TreeNode* root) {
        long long ans=0, first, last;
        if(root==nullptr){
            return ans;
        }
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            long long size = q.size();
            long long min_val = q.front().second;
            for(int i=0; i<size; i++){
                pair<TreeNode*, long long> p = q.front();
                q.pop();
                long long  curr_val = p.second-min_val;
                if(i==0) first = curr_val;
                if(i==size-1) last = curr_val;
                if(p.first->left){
                    q.push({p.first->left, 2*curr_val+1});
                }
                if(p.first->right){
                    q.push({p.first->right, 2*curr_val+2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }