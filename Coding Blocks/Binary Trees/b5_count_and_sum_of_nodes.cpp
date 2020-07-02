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

//Post-order  TC: O(N)
int getCount(node* root){
    if(root == NULL)
        return 0;
    return getCount(root->left) + getCount(root->right) + 1;
}

//Post-order  TC: O(N)
int getSum(node* root){
    if(root == NULL)
        return 0;
    return getSum(root->left) + getSum(root->right) + root->data;
}

int main(){

    node* root = buildTree();
    cout<<"Count"<<endl;
    cout<<getCount(root);
    cout<<endl;
    cout<<"Sum"<<endl;
    cout<<getSum(root);
    cout<<endl;
    return 0;
}