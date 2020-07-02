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
    if(d == -1)
        return NULL;
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

//TC: O(n) SC: O(n)
void BFSTraversal(node* root){
    queue<node*> bfs_queue;
    bfs_queue.push(root);

    while(!bfs_queue.empty()){
        node* f = bfs_queue.front();
        cout<<f->data<<" ";
        bfs_queue.pop();
        if(f->left){
            bfs_queue.push(f->left);
        }
        if(f->right){
            bfs_queue.push(f->right);
        }
    }
    return;
}

int main(){
    node* root = buildTree();
    BFSTraversal(root);
    cout<<endl;
    return 0;
}