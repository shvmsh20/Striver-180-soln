//Level Order
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        if(root==nullptr) return res;
        while(!q.empty()){
            int size = q.size();
            vector<int> x;
            for(int i=0; i<size; i++){
                auto *t = q.front();
                q.pop();
                x.push_back(t->val);
                if(t->left!=nullptr){
                    q.push(t->left);
                }
                if(t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(x);
        }
        return res;
    }

//Spiral level order using deque
vector<int> findSpiral(Node *root)
{
    //Your code here
    deque<Node*> dq;
    vector<int> res;
    if(root==NULL) return res;
    dq.push_front(root);
    bool rev = true;
    while(!dq.empty()){
        int n = dq.size();
        for(int i=0; i<n; i++){
            if(rev==false){
                auto x = dq.front();
                res.push_back(x->data);
                if(x->left){
                    dq.push_back(x->left);
                }
                if(x->right){
                    dq.push_back(x->right);
                }
                dq.pop_front();
            
            }else{
                auto x = dq.back();
                res.push_back(x->data);
                if(x->right){
                    dq.push_front(x->right);
                }
                if(x->left){
                    dq.push_front(x->left);
                }
                dq.pop_back();
            }
        }
        
        rev = !rev;
    }
    return res;
}


//Binary Tree Zigzag Level Order Traversal

//By reversing vector
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool is_reverse = false;
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(is_reverse){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            is_reverse = !is_reverse;
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
};