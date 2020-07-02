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

void printKthDistanceNodesFromTargetNode(node* root, int t, int k){
    static int relativeK = -1;
    if(root == NULL)
        return;
    if(t == root->data)
        relativeK = 0;
    if(relativeK == k)
        cout<<root->data<<" ";

    if(relativeK == -1)
        printKthDistanceNodesFromTargetNode(root->left, t, k);
    else{
        relativeK++;
        printKthDistanceNodesFromTargetNode(root->left, t, k);
    } 
    if(relativeK == -1)
        printKthDistanceNodesFromTargetNode(root->right, t, k);
    else{
        relativeK++;
        printKthDistanceNodesFromTargetNode(root->right, t, k);
    }
    return;
}

int main(){
    node* root = buildTree();
    printKthDistanceNodesFromTargetNode(root, 5, 1);
    return 0;
}