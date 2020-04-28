#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct node{
int data;
node *left;
node *right;
};

node *root , *temp , *ptr;

node * creation();
int sumFromRootToNode(node * , int);
node * getSpecificNode(node * , int );
int  insert(node * ,node *);
int main()
{   int choice;
    node *ptr1;
    ptr1 = creation();
    cout<<"Enter node value to find sum from root"<<endl;
    int val;
    cin>>val;
    /*node * temp2 = getSpecificNode(ptr1,val);*/
    int ans = sumFromRootToNode(ptr1,val);
    cout<<"Total sum is : "<<ans;
}
node * getSpecificNode(node * root , int val){
    if(root != NULL){
        getSpecificNode(root->left,val);
        if(root->data == val)
            return root;
        getSpecificNode(root->right,val);
    }
}
int sumFromRootToNode(node * root , int val){
    if(root == NULL){
        return -1;
    }
    if(root->data == val){
        return root->data;
    }
    int lv = sumFromRootToNode(root->left,val);
    if(lv >= 0){
        return lv+root->data;
    }else{
        int rv = sumFromRootToNode(root->right,val);
        if(rv>=0){
            return rv+root->data;
        }else{
            return rv;
        }
    }
}
node *creation(){

   // creation of tree

   root = NULL;
   int ch ;
   do{
      temp = (node *)malloc(sizeof(node));
      cout<<"Enter data :"<<endl;
      cin>>temp->data;
      temp->right = NULL;
      temp->left = NULL;

      if(root == NULL)
      {
          root = temp;
          cout<<"Root node created !!"<<endl;
      }
      else
      {
          insert(root , temp);
      }

      cout<<"Do you want to add more data :"<<endl;
      ch = getch();
   }while(ch == 'y' || ch == 'Y');
   cout<<"Insertion in Binary Tree is completed !! "<<endl;

   return root;
}

int insert(node *root ,node *temp)
{
    // insertion of elements in a tree

    int ch;
    cout<<"Where do you want to insert the data : right (r) or left(l)"<<endl;
    ch = getch();

    if( ch == 'r')
    {
        if(root->right == NULL)
            {root->right = temp;
            cout<<"Data inserted "<<endl;}
        else
            insert(root->right , temp);

    }

    if(ch == 'l')
    {
        if(root->left == NULL)
           {
             root->left = temp;
            cout<<"Data inserted "<<endl;}
        else
            insert(root->left, temp);
    }
}

