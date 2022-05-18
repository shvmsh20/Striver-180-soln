class BSTIterator{
    public:
    
       stack<TreeNode* > st;
       int index=0;
       bool reverse;
    
       BSTIterator(TreeNode *root, bool rev){
           reverse = rev;
           pullnodes(root);
       } 
    
       void pullnodes(TreeNode* curr){
           if(reverse==false){
               while(curr){
                   st.push(curr);
                   curr = curr->left;
               }
           }else{
               while(curr){
                   st.push(curr);
                   curr = curr->right;
               }
           }
       }
    
       int next(){
           TreeNode* curr = st.top();
           st.pop();
           int res = curr->val;
           if(reverse==false){
               curr = curr->right;
               pullnodes(curr);
           }else{
               curr = curr->left;
               pullnodes(curr);
           }
           return res;
       } 
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator h(root, true);
        int x = l.next();
        int y = h.next();
        while(x<y){
            if(x+y<k){
                x = l.next();
            }else if(x+y>k){
                y = h.next();
            }else{
                return true;
            }
        }
        return false;
    }
};