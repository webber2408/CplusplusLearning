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

node* buildTree(int arr[], int l, int r){
    int m = l+(r-l)/2;
    if(l > r)
        return NULL;
    node* root = new node(arr[m]);
    root->left = buildTree(arr, l, m-1);
    root->right = buildTree(arr, m+1, r);
    return root;
}

node* buildTreeFromArray(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    node* root = buildTree(arr, 0, N-1);
    return root;
}

void printTree(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}

int main(){
    node* root = buildTreeFromArray();
    printTree(root);
    return 0;
}