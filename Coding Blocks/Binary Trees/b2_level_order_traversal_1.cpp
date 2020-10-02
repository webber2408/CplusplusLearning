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

int getHeight(node* root){
    if(root == NULL){
        return 0;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void printPreOrder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printKthLevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    node* root = buildTree();
    
    cout<<"Tree Traversal: Pre-Order"<<endl;
    printPreOrder(root);

    cout<<endl<<"Height"<<endl;
    int height = getHeight(root);
    cout<<height<<endl;

    cout<<"3rd level"<<endl;
    printKthLevel(root, 3);
    cout<<endl;

    cout<<"Level Order Traversal"<<endl;
    //O(n2) => WC: Skewed Tree
    for(int i=1;i<=height;i++){
        printKthLevel(root, i);
    }
    cout<<endl;

    return 0;
}
/*
4 2 12 -1 -1 14 -1 -1 1 11 -1 -1 15 -1 -1

<== Output ==>

Tree Traversal: Pre-Order
4 2 12 14 1 11 15 
Height
3
3rd level
12 14 11 15 
Level Order Traversal
4 2 1 12 14 11 15 
*/