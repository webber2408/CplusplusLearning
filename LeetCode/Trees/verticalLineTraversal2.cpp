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

void getVerticalOrder(node* root, int hd, map<int, vector<int>> &m) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Store current node in map 'm' 
    m[hd].push_back(root->data);
  
    // Store nodes in left subtree 
    getVerticalOrder(root->left, hd-1, m); 
  
    // Store nodes in right subtree 
    getVerticalOrder(root->right, hd+1, m); 
}
  
// The main function to print vertical order of a binary tree 
// with the given root 
void printVerticalOrder(node* root) 
{ 
    // Create a map and store vertical order in map using 
    // function getVerticalOrder() 
    map < int,vector<int> > m; 
    int hd = 0; 
    getVerticalOrder(root, hd,m); 
  
    // Traverse the map and print nodes at every horigontal 
    // distance (hd) 
    map< int,vector<int> > :: iterator it; 
    for (it=m.begin(); it!=m.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
    } 
} 

int main(){
    node* root = buildTree();
    printVerticalOrder(root);
    return 0;
}