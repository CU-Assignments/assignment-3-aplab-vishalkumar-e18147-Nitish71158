bool ismiror(TreeNode*root1, TreeNode*root2){
        if (root1== nullptr && root2 == nullptr) {
            return true;
        }
        
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        return root1->val == root2->val && ismiror(root1->left, root2->right) && ismiror(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return ismiror(root->left,root->right);
    }
