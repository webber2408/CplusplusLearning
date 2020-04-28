#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node * next;
}*start1,*start2;
class single_llist
{
private:
    node *start;
    public:
        node* create_node(int);
        node * insert_begin(node *);
        void delete_pos();
        void display(node *);
        single_llist(node *start)
        {
            start = NULL;
        }
};
node * mergeListrecursion(node *,node *);
void displayComplete(node *);
int main(){
    int choice, nodes, element, position, i;
    single_llist sl(start1);
    single_llist s2(start2);
    int flag1 = 0,flag2 = 0;
    while (flag1 == 0)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list 1"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Delete a Particular Node"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit and move to linked list 2"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            start1 = sl.insert_begin(start1);
            cout<<endl;
            break;
        case 2:
            cout<<"Delete a particular node: "<<endl;
            sl.delete_pos();
            break;
        case 3:
            cout<<"Display elements of link list"<<endl;
            sl.display(start1);
            cout<<endl;
            break;
        case 4:
            flag1 = 1;
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }


    while (flag2 == 0)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list 2"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Delete a Particular Node"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            start2 = s2.insert_begin(start2);
            cout<<endl;
            break;
        case 2:
            cout<<"Delete a particular node: "<<endl;
            s2.delete_pos();
            break;
        case 3:
            cout<<"Display elements of link list"<<endl;
            s2.display(start2);
            cout<<endl;
            break;
        case 4:
            flag2 = 1;
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }

    node *newHead = mergeListrecursion(start1,start2);
    displayComplete(newHead);
}
node * single_llist::create_node(int n){
    node *temp;
    temp = new(node);
    if(temp == NULL){
        cout<<"Error creating node"<<endl;
        return 0;
    }else{
        temp->value = n;
        temp->next = NULL;
        return temp;
    }
}
node * single_llist::insert_begin(node *startTemp){
    cout<<"Enter value to insert in the beginning:"<<endl;
    int n;
    cin>>n;
    node *temp = create_node(n);
    if(startTemp == NULL){
        startTemp = temp;
        startTemp->next = NULL;
    }else{
        temp->next = startTemp;
        startTemp = temp;
    }

    return startTemp;
}

void single_llist::display(node *startTemp)
{
    node *temp;
    if (startTemp == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = startTemp;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void single_llist::delete_pos(){
    cout<<"Enter position to delete from :"<<endl;
    int pos;
    cin>>pos;
    node *p;
    node *s = start;
    int counter = 0;
    if(pos == 1){
        start = start->next;
    }else{
         while(counter != pos-1){
            p = s;
            s=s->next;
            counter++;
        }
        p->next = s->next;
    }

    free(s);
}
void displayComplete(node *newHead){
    node *temp;
    if (newHead == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = newHead;
    cout<<"Elements of merged list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
node * mergeListrecursion(node *start1 , node *start2){
    if(start1 == NULL){
        return start2;
    }
    if(start2 == NULL){
        return start1;
    }
    node *currentHead = start1->value>start2->value?start2:start1;
    if(currentHead==start1){
        currentHead->next = mergeListrecursion(start1->next,start2);
    }else{
        currentHead->next = mergeListrecursion(start1,start2->next);
    }

    return currentHead;
}
