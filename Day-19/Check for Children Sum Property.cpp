void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
	if(root==nullptr){
		return;
	}
	int sum = 0;
	if(root->left){
		sum+= root->left->data;
	}
	if(root->right){
		sum+= root->right->data;
	}
	if(root->data>sum){
		if(root->left) root->left->data = root->data;
		if(root->right) root->right->data = root->data;
	}else{
		root->data = sum;
	}
	changeTree(root->left);
	changeTree(root->right);
	sum = 0;
	if(root->left){
		sum+= root->left->data;
	}
	if(root->right){
		sum+= root->right->data;
	}
	if(root->left || root->right) root->data = sum;
} 