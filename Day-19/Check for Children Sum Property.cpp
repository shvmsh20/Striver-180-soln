//M-1 T/C: O(N)
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

//M-2 T/C: O(n^2)
void increment(BinaryTreeNode < int > * root, int val){
	if(root->left){
		root->left->data+= val;
		increment(root->left, val);
	}else if(root->right){
		root->right->data+= val;
		increment(root->right, val);
	}
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
	if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
		return;
	}
	changeTree(root->left);
	changeTree(root->right);
	int tot = 0, diff;
	if(root->left){
		tot+= root->left->data;
	}
	if(root->right){
		tot+= root->right->data;
	}
	diff = tot - root->data; 
	
	if(diff>=0){
		root->data+= diff;
	}else{
		increment(root, -1*diff);
	}
	
} 