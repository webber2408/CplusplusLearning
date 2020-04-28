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
int countSingleChild(node *);
int  insert(node * ,node *);
int main()
{   int choice;
    node *ptr1;
    ptr1 = creation();
    int ans = countSingleChild(ptr1);
    cout<<"Total single child nodes are : "<<ans;
}
int countSingleChild(node * root){
    if(root==NULL){
        return 0;
    }
    int lc = countSingleChild(root->left);
    int rc = countSingleChild(root->right);
    if((root->left==NULL && root->right != NULL) || (root->left!=NULL && root->right == NULL)) {
        return lc+rc+1;
    }else{
        return lc + rc ;
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

