/*
Note:
A balanced tree always has a height of O(logn)
*/
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

pair<int, bool> getHeight(node* root){
    if(root == NULL)
        return make_pair(0, true);
    
    pair<int, bool> left = getHeight(root->left);
    pair<int, bool> right = getHeight(root->right);

    if(abs(left.first - right.first) <= 1 && (left.second == right.second == true))
        return make_pair(max(left.first, right.first) + 1, true);
    else
        return make_pair(max(left.first, right.first) + 1, false);
};

int main(){

    node* root = buildTree();

    cout<<"Height: "<<getHeight(root).first<<endl;
    bool isHeightBalanced = getHeight(root).second;
    if(isHeightBalanced)
        cout<<"Tree is height balanced"<<endl;
    else
        cout<<"Not height balanced"<<endl;

    return 0;
}