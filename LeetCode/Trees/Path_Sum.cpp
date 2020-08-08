#include<iostream>
#include<unordered_map>
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

// Method 2 (Not right?)

void getPathsHelper(node* root, int &count1, int sum, int &currSum, unordered_map<int, int> &m){
    currSum += root->data;
    cout<<currSum<<" = "<<(currSum-root->data)<<" + "<<root->data<<endl;

    cout<<"CurrSum "<<currSum<<" toSearch"<<(currSum-sum)<<endl;
    if(m.find(currSum - sum) != m.end()){
        count1 += m[currSum-sum];
    }

    m[currSum]++;

    if(root->left)
        getPathsHelper(root->left, count1, sum, currSum, m);
    if(root->right)
        getPathsHelper(root->right, count1, sum, currSum, m);

}

int getPathsOptimised(node* root, int sum){
    if(root == NULL)
        return 0;
    unordered_map<int, int>m;
    m[0] = 1;
    int count1 = 0;
    int currSum = 0;
    getPathsHelper(root, count1, sum, currSum, m);

    for(auto i = m.begin(); i != m.end(); i++)
        cout<<i->first<<" - "<<i->second<<endl;

    return count1;
}



int main(){

    node* root = buildTree();
    int sum;
    cin>>sum;

    // getPaths(root, sum);

    int count1 = getPathsOptimised(root, sum);

    cout<<"Count: "<<count1<<endl;

    return 0;
}