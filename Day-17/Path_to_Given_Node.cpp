//T/C: O(n), S/C: O(H)
bool util(TreeNode *root, int target, vector<int> &ans){
    if(root==NULL){
        return false;
    }
    ans.push_back(root->val);
    if(root->val==target){
        return true;
    }else if(util(root->left, target, ans) || util(root->right, target, ans)){
        return true;
    }else{
        ans.pop_back();
        return false;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    util(A, B, ans);
    return ans;
}
