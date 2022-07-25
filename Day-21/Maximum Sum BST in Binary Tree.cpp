vector<int> solve(TreeNode* root, int &res){
        if(root==nullptr){
            return {0, INT_MIN, INT_MAX};
        }
        //{sum of nodes of BST, largest, smallest}
        auto left = solve(root->left, res);
        auto right = solve(root->right, res);
        int low = left[1];
        int high = right[2];
        int value;
        if(root->val>low && root->val<high){
            value = left[0]+right[0]+root->val;
            res = max(res, value);
            return {value, max(root->val, right[1]), min(root->val, left[2])};
        }else{
            value = max(left[0], right[0]);
            return {value, INT_MAX, INT_MIN};
        }
        
    }
    int maxSumBST(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res<0?0:res;
    }
//OR
int res = INT_MIN;
    struct Node{
        int sum;
        int mn;
        int mx;
        Node(int s, int x, int y){
            sum = s;
            mn = x;
            mx = y;
        }
    };
    Node* util(TreeNode* root){
        if(root==nullptr){
            return new Node(0, INT_MAX, INT_MIN);
        }
       
        Node* l = util(root->left);
        Node* r = util(root->right);
        if(l->mx<root->val && root->val<r->mn){
            int currSum = (l->sum)+(r->sum)+(root->val);
            res = max(res, currSum);
            int currMn = min(l->mn, root->val);
            int currMx = max(r->mx, root->val);
            Node* t = new Node(currSum, currMn, currMx);
            return t;
        }else{
            Node* t = new Node(max(l->sum, r->sum), INT_MIN, INT_MAX);
            return t;
        }
    }
    int maxSumBST(TreeNode* root) {
        Node* t = util(root);
        return max(0, res);
    }