vector<int>ZigZag(node *root){
    vector<int>ans;
    if(!root){
        return ans;
    }
    bool direction=true;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            node *temp=q.front();
            q.pop();
            int index=direction ? i :n - i- 1;
            arr[index]=temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        for(auto i : arr){
            ans.push_back(i);
        }
        direction=!direction;
    }
    return ans;
}
