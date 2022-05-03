//M-1
void solve(int level, Node *root, unordered_map<int, Node*> &mp){
        if(root==nullptr){
            return;
        }
        solve(level+1, root->right, mp);
        if(mp.find(level)!=mp.end()){
            root->next = mp[level];
        }
        mp[level] = root;
        solve(level+1, root->left, mp);
    }
    Node* connect(Node* root) {
        unordered_map<int, Node*> mp;
        solve(0, root, mp);
        return root;
    }

//M-2
Node* connect(Node* root) {
    if(root==nullptr){
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            if(i!=n){
                curr->next = q.front();
            }
            
        }
    }
    return root;
}   

//M-3
Node* connect(Node* root) {
        if(root==nullptr){
           return root;
        } 
        Node *curr = root, *next = root->left;
        while(curr && next){
            curr->left->next = curr->right;
            if(curr->next){
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
            if(curr==nullptr){
                curr = next;
                next = curr->left;
            }
        }
        return root;
    }