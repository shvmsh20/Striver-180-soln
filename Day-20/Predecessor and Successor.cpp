void pred(Node* root, Node*& pre, int key){
    if(root==NULL){
        return;
    }
    if(root->key<key){
        pre = root;
        pred(root->right, pre, key);
    }else if(root->key>=key){
        pred(root->left, pre, key);
    }
    return;
}
void succ(Node* root, Node*& suc, int key){
    if(root==NULL){
        return;
    }
    if(root->key>key){
        suc = root;
        succ(root->left, suc, key);
    }else if(root->key<=key){
        succ(root->right, suc, key);
    }
    return;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

pre = NULL;
suc = NULL;
pred(root, pre, key);
succ(root, suc, key);

}