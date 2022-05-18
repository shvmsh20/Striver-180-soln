int kthLargest(Node *root, int &K)
    {
        //Your code here
        if(root==NULL){
            return -1;
        }
        int right = kthLargest(root->right, K);
        if(right!=-1){
            return right;
        }
        if(K==1){
            return root->data;
        }
        K--;
        return kthLargest(root->left, K);
    }