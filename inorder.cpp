void inorder(TreeNode *root,vector<int>&ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        inorder(root, ans);
        return ans;
    }
