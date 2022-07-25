//M-1
int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            TreeNode *curr = st.top();
            st.pop();
            if(k==1){
                return curr->val;
            }
            k--;
            root = curr->right;
        }
        return -1;
    }


 //M-2   
 int helper(TreeNode* root, int &k){
        if(root==nullptr){
            return -1;
        }
        int left = helper(root->left, k);
        if(left!=-1){
            return left;
        }
        cout << k << " ";
        if(k==1){
            return root->val;
        }
        k--;
        return helper(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }

//M-3

int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        while(root!=nullptr){
            if(root->left==nullptr){
                if(k==1){
                    res =  root->val;
                }
                k--;
                
                root = root->right;
            }else{
                TreeNode *prev = root->left;
                while(prev->right && prev->right!=root){
                    prev = prev->right;
                }
                if(prev->right==nullptr){
                    prev->right = root;
                    root = root->left;
                }else{
                    prev->right = nullptr;
                    if(k==1){
                        res =  root->val;
                    }
                    k--;
        
                    root = root->right;
                    
                }
            }
            
        }
        return res;