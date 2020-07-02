#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

//Method 1 => Pushing pair of node and level and adding a new line if level changes
void newLineBFSTraversal(node* root){
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 1));
    int lastLevel = 1;

    while(!q.empty()){
        pair<node*, int> p = q.front();
        if(p.second != lastLevel){
            cout<<endl;
            lastLevel = p.second;
        }
        cout<<p.first->data<<" ";
        q.pop();
        if(p.first->left)
            q.push(make_pair(p.first->left, p.second+1));
        if(p.first->right)
            q.push(make_pair(p.first->right, p.second+1));
    }
    return;
}

void newLineBFSTraversal2(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*f = q.front();
        q.pop();
        if(f == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }else{
            cout<<f->data<<" ";
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
    return;
}

int main(){

    node* root = buildTree();
    newLineBFSTraversal(root);
    cout<<endl;
    newLineBFSTraversal2(root);
    return 0;
}