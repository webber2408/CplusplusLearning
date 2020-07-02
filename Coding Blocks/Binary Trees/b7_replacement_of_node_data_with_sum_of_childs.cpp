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

int replaceByChildSum(node* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    int temp = root->data;
    root->data = replaceByChildSum(root->left) + replaceByChildSum(root->right);
    return root->data+temp;
}

void preOrderTraversal(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    node* root = buildTree();
    cout<<replaceByChildSum(root);
    cout<<endl;
    cout<<"Pre-order traversal"<<endl;
    preOrderTraversal(root);
    cout<<endl;
    return 0;
}