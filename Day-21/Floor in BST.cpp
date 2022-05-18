void helper(TreeNode<int> *node, int x, int &res){
	if(node==nullptr){
		return;
	}
	if(node->val<=x){
		res = node->val;
		helper(node->right, x, res);
	}else{
		helper(node->left, x, res);
	}
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
	int res=-1;
	helper(root, X, res);
	return res;
}