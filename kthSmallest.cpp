int solve(node* root,int k,int &i){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,k,i);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,k,i);
}

int kthSmallest(node* root, int k) {
    // Write your code here.
    int i=0;
    int ans=solve(root,k,i);
    return ans;
}
