bool isTrue(TreeNode*root,int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->val>=min && root->val<=max){
        bool left=isTrue(root->left,min,root->val);
        bool right=isTrue(root->right,root->val,max);
        return left && right;
    }
    else{
        return false;
    }
}
    bool isValidBST(TreeNode* root) {
       if(root==NULL){
        return true;
    }
    return isTrue(root,INT_MIN,INT_MAX);
 }
