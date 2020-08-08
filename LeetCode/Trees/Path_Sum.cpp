#include<iostream>
using namespace std;

int count = 0;

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

void getPathsCountForNode(node* root, int targetSum, int currSum){
    if(root == NULL)
        return;

    currSum += root->data;

    if(currSum == targetSum)
        count++;
    
    getPathsCountForNode(root->left, targetSum, currSum);
    getPathsCountForNode(root->right, targetSum, currSum);
    return;
}

void getPaths(node* root, int sum){
    if(root == NULL)
        return;
    
    getPathsCountForNode(root, sum, 0);

    getPaths(root->left, sum);
    getPaths(root->right, sum);
    return;
}

int main(){

    node* root = buildTree();
    int sum;
    cin>>sum;

    getPaths(root, sum);

    cout<<"Cont: "<<count<<endl;

    return 0;
}