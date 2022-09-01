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

void rightViewBreadthFirst(node* root){
    queue<pair<node*, int>> q;
    stack <node*> result;
    vector<int> resultVector;
    result.push(root);
    q.push(make_pair(root, 1));
    int lastLevel = 1;
    while(!q.empty()){
        pair<node*, int> f = q.front();
        if(f.second == lastLevel){
            result.pop();
            result.push(f.first);
        }else{
            result.push(f.first);
            lastLevel = f.second;
        }
        q.pop();
        if(f.first->left)
            q.push(make_pair(f.first->left, f.second+1));
        if(f.first->right)
            q.push(make_pair(f.first->right, f.second+1));
    }

    while(!result.empty()){
        resultVector.push_back(result.top()->data);
        result.pop();
    }

    for(int i=(resultVector.size()-1);i>=0;i--){
        cout<<resultVector[i]<<" ";
    }

    return;
}

void rightViewDepthFirst(node* root, int current_level){
    if(root == NULL)
        return;
    static int max_level = -1;
    if(max_level < current_level){
        cout<<root->data<<" ";
        max_level = current_level;
    }
    if(root->right)
        rightViewDepthFirst(root->right, current_level+1);
    if(root->left)
        rightViewDepthFirst(root->left, current_level+1);
    return;
}

int main(){
    node* root = buildTree();
    rightViewBreadthFirst(root);
    cout<<endl;
    rightViewDepthFirst(root,1);
    return 0;
}