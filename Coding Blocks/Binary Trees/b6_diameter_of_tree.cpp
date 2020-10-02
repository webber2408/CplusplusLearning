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

int getMaxDepth(node* root){
    if(root == NULL)
        return 0;
    return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
}

//Diameter O(N2) D = max(h1+h2, d1, d2);
int getDiameter(node* root){
    if(root == NULL)
        return 0;
    return max(max(getDiameter(root->left), getDiameter(root->right)), (getMaxDepth(root->left) + getMaxDepth(root->right)));
}

class Pair{
    public:
        int height;
        int diameter;
};

Pair getFastDiameter(node* root){
    Pair p;
    if(root == NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    Pair leftPair = getFastDiameter(root->left);
    Pair rightPair = getFastDiameter(root->right);

    p.height = max(leftPair.height, rightPair.height) + 1;
    p.diameter = max((leftPair.height + rightPair.height),  max(leftPair.diameter, rightPair.diameter));
    return p;
}

int main(){

    node* root = buildTree();
    cout<<"Diameter"<<endl;
    cout<<getDiameter(root);
    cout<<endl;
    cout<<"Fast Diameter"<<endl;
    Pair p = getFastDiameter(root);
    cout<<p.diameter;
    cout<<endl;

    return 0;
}
