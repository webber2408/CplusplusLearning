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

void printPost(node* root){
    if(root == NULL)
        return;
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}
void printPre(node* root){
    if(root == NULL)
        return;
    printPre(root->left);
    printPre(root->right);
    cout<<root->data<<" ";
}
void printIn(node* root){
    if(root == NULL)
        return;
    printIn(root->left);
    printIn(root->right);
    cout<<root->data<<" ";
}
int height(node* root){
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int main(){

    node* root = buildTree();
    cout<<"Post order traversal:"<<endl;
    printPost(root);
    cout<<endl<<"Height"<<endl;
    cout<<height(root)<<endl;
    return 0;
}