#include<iostream>
using namespace std;

struct node{
int data;
node *left;
node *right;
};

node *root , *temp , *ptr;

node * creation();
int  insert(node * ,node *);
int pretraversal( node *);
int posttraversal( node *);
int intraversal( node *);
int main()
{   int choice;
    node *ptr1;
    ptr1 = creation();
    cout<<"Enter type of traversal you want to display the elements : 1. inorder 2. Postorder 3. preorder "<<endl;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1 : intraversal(ptr1); break;
        case 2 : posttraversal(ptr1); break;
        case 3 : pretraversal(ptr1); break;
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
   cout<<<"Insertion in Binary Tree is completed !! "<<endl;

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

int intraversal(node *ptr1)
{

  if(ptr1 != NULL)
  {
      intraversal(ptr1->left);
      cout<<ptr1->data;
      intraversal(ptr1->right);
  }
}
int pretraversal(node *ptr1)
{

  if(ptr1 != NULL)
  {
      cout<<ptr1->data;
      pretraversal(ptr1->left);
      pretraversal(ptr1->right);
  }
}
int posttraversal(node *ptr1)
{

  if(ptr1 != NULL)
  {

      posttraversal(ptr1->left);
      posttraversal(ptr1->right);
      cout<<ptr1->data;
  }
}









