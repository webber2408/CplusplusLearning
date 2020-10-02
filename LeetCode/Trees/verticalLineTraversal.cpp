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

void findExtremes(node* root, int* minX, int* maxX, int currentX){

    if(root == NULL)
        return;

    if(currentX < *minX) *minX = currentX;
    if(currentX > *maxX) *maxX = currentX;

    findExtremes(root->left, minX, maxX, currentX-1);
    findExtremes(root->right, minX, maxX, currentX+1);

    return;
}

void printNodeOnLine(node* root, int targetX, int currentX, vector<int> &inner_result){
    if(root == NULL)
        return;
    if(targetX == currentX){
        cout<<root->data<<" ";
        inner_result.push_back(root->data);
    }
    printNodeOnLine(root->left, targetX, currentX-1, inner_result);
    printNodeOnLine(root->right, targetX, currentX+1, inner_result);
    return; 
}

vector<vector<int>> verticalLineTraversal(node* root){
    int minX = 0, maxX = 0;
    findExtremes(root, &minX, &maxX, 0);
    vector<vector<int>> result;

    // cout<<"Extremes =  Min: "<<minX<<" Max: "<<maxX<<endl;

    for(int i=minX; i<=maxX; i++){
        vector<int> inner_result;
        printNodeOnLine(root, i, 0, inner_result);
        sort(inner_result.begin(), inner_result.end());
        result.push_back(inner_result);
    }

    return result;
}

void print(node* root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

int main(){
    node* root = buildTree();
    
    print(root);
    cout<<endl;

    vector<vector<int>> result = verticalLineTraversal(root);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}