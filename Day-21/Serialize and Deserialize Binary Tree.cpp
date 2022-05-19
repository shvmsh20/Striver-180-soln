string serialize(TreeNode* root) {
        string s = "";
        if(root==nullptr){
            return s;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr!=nullptr){
                s.append(to_string(curr->val)+",");   
                q.push(curr->left);
                q.push(curr->right);
            }else{
                s.append("#,");
            }   
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        string str;
        stringstream s(data);
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="#"){
                curr->left=nullptr;
            }else{
                TreeNode *temp = new TreeNode(stoi(str));
                q.push(temp);
                curr->left=temp;
            }
            getline(s, str, ',');
            if(str=="#"){
                curr->right=nullptr;
            }else{
                TreeNode *temp = new TreeNode(stoi(str));
                q.push(temp);
                curr->right=temp;
            }
        }
        return root;
    }