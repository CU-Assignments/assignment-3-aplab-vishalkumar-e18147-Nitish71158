    void sideview(TreeNode* root,vector<int>&ans, int lvl){
        if(!root){
            return;
        }
        if(lvl==ans.size()){
            ans.push_back(root->val);
        }
        sideview(root->right,ans,lvl+1);
        sideview(root->left,ans,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        sideview(root,ans,0);
        return ans;
    }
