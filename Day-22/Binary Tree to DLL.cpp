 Node* prev = nullptr;
    Node * bToDLL(Node *root)
    {
        // your code here
        if(root==nullptr){
            return nullptr;
        }
        Node* head = bToDLL(root->left);
        if(prev!=nullptr){
            prev->right = root;
            root->left = prev;
        }else{
            head = root;
        }
        prev = root;
        bToDLL(root->right);
        return head;
    }