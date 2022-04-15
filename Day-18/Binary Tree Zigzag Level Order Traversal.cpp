//Using flag
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==nullptr) return res;
        queue<TreeNode *> q;
        q.push(root);
        bool lTor = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i=0; i<n; i++){
                TreeNode* x = q.front();
                q.pop();
                int index = lTor?i:n-1-i;
                temp[index] = x->val;
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
            res.push_back(temp);
            lTor = !lTor;
        }
        return res;
    }
    
//Using 2 stacks
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int> temp;
            while(!s1.empty()){
                TreeNode *node = s1.top();
                s1.pop();
                temp.push_back(node->val);
                if(node->left){
                    s2.push(node->left);
                }
                if(node->right){
                    s2.push(node->right);
                }
            }
            res.push_back(temp);
            temp.clear();
            while(!s2.empty()){
                TreeNode *node = s2.top();
                s2.pop();
                temp.push_back(node->val);
                if(node->right){
                    s1.push(node->right);
                }
                if(node->left){
                    s1.push(node->left);
                }
            }
            if(!temp.empty()) res.push_back(temp);
        }
        return res;
    }