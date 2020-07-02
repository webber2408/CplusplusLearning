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

node* buildTree(int *inorder, int *preorder, int l, int r){
    if(l>r)
        return NULL;
    static int i=0;
    node* root = new node(preorder[i]); //Created root

    //search for the root in preorder array
    int index = -1;
    for(int j=0;j<=r;j++){
        if(inorder[j] == root->data){
            index = j;
            break;
        }
    }
    i++;
    //Build the child nodes now
    root->left = buildTree(inorder, preorder, l, index-1);
    root->right = buildTree(inorder, preorder, index+1, r);

    return root;
}

int getHeight(node* root){
    if(root == NULL)
        return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void printKthLevel(node* root, int k){
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void levelOrderTraversal(node* root){
    int height = getHeight(root);
    
    for(int i=1;i<=height;i++){
        printKthLevel(root, i);
        cout<<endl;
    }

    return;
}

int main(){

    int in[7] = {3, 1, 5, 4, 6, 2, 7};
    int pre[7] = {4, 1, 3, 5, 2, 6, 7};

    node* root = buildTree(in, pre, 0, 6);
    levelOrderTraversal(root);

    return 0;
}