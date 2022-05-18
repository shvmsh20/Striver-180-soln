int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
	int res=-1;
		while(node){
			if(node->data==x){
				res = node->data;
				break;
			}else if(node->data<x){
				node = node->right;
			}else{
				res = node->data;
				node = node->left;
			}
		}
		return res;
}