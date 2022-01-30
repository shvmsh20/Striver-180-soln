// T/C: O(n*m)
Node *merge(Node *a, Node *b){
    Node *temp = new Node(0), *res;
    res = temp;
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            temp->bottom = a;
            temp = temp->bottom; 
            a = a->bottom;
        }else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    if(a==NULL){
            temp->bottom = b;
        }else{
            temp->bottom = a;
    }
    return res->bottom;
}    
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL){
       return root;
   }
   root->next = flatten(root->next);
   root = merge(root, root->next);
   return root;
}

