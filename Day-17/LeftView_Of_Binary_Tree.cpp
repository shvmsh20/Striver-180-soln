//Iterative
vector<int> v;
   if(root==NULL){
       return v;
   }
   queue<Node *> q;
   q.push(root);
   while(q.empty()==false){
       int size = q.size();
       for(int i=0; i<size; i++){
           Node *temp = q.front();
           q.pop();
           if(i==0){
               v.push_back(temp->data);
           }
           if(temp->left){
               q.push(temp->left);
           }
           if(temp->right){
               q.push(temp->right);
           }
       }
   }
   return v;

//Recursive
   void util(Node *root, int level, vector<int> &res){
    if(root==NULL){
        return;
    }
    if(level==res.size()){
        res.push_back(root->data);
    }
    util(root->left, level+1, res);
    util(root->right, level+1, res);
    
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   util(root, 0, res);
   return res;
}