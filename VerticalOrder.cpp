
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

node *insertion(node *root){
    cout<<"Enter your data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the left root node of data: "<<data<<endl;
    root->left=insertion(root->left);
    cout<<"Enter the right root node of data: "<<data<<endl;
    root->right=insertion(root->right);
    return root;
}

void bfs(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<' ';
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
            }
        }

    }
}

vector<int>verticalOrder(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,map<int,vector<int>>>m;
    queue<pair<node*,pair<int,int>>>q;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int,int>>temp=q.front();
        node*frontdata=temp.first;
        int hzr=temp.second.first;
        int lvl=temp.second.second;
        m[hzr][lvl].push_back(frontdata->data);
        q.pop();
        if(frontdata->left){
            q.push(make_pair(frontdata->left,make_pair(hzr-1,lvl+1)));
        }
        if(frontdata->right){
            q.push(make_pair(frontdata->right,make_pair(hzr+1,lvl+1)));
        }                                 
    }
    for(auto i:m){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }

}



int main(){
    node *root=NULL;
    root=insertion(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    bfs(root);
    for(auto i:verticalOrder(root)){
        cout<<i<<" ";
    }
}
