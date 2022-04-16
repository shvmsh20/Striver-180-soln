void inorder(TreeNode<int>* root, vector<int> &res){
	if(root->left==NULL && root->right==NULL){
		res.push_back(root->data);
		return;
	}
	if(root->left) inorder(root->left, res);
	
	if(root->right) inorder(root->right, res);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    
	vector<int> res;
	if(root==NULL){
		return res;
	}
	res.push_back(root->data);
	if(root->left==NULL && root->right==NULL){
		return res;
	}
	TreeNode<int>* curr = root;
    curr = curr->left;
	while(curr!=NULL){
		if(!(curr->left==NULL && curr->right==NULL)){
			res.push_back(curr->data);
		}
		if(curr->left!=NULL){
			curr = curr->left;
		}else {
			curr = curr->right;
		}
		
	}
	
	inorder(root, res);	
	
	curr = root;
	stack<int> st;
	curr = curr->right;
	while(curr!=NULL){
		if(!(curr->right==NULL && curr->left==NULL)){
			st.push(curr->data);
		}
		if(curr->right!=NULL){
			curr = curr->right;
		}else {
			curr = curr->left;
		}
	}
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}
	return res;
}