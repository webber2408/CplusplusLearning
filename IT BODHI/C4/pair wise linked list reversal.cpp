#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node * next;
}*start;
class single_llist
{
    public:
        node* create_node(int);
        void insert_begin();
        void insert_pos();
        void insert_last();
        void delete_pos();
        void sort();
        void search();
        void update();
        void reverse();
        void display();
        node * reverse_recursion_pairwise(node *start);
        single_llist()
        {
            start = NULL;
        }
};
int main(){
    int choice, nodes, element, position, i;
    single_llist sl;
    start = NULL;
    node *temp1;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Display Linked List"<<endl;
        cout<<"9.Reverse Linked List "<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"11.Reverse (Recursion Pairwise) "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Sort Link List: "<<endl;
            sl.sort();
            cout<<endl;
            break;
        case 5:
            cout<<"Delete a particular node: "<<endl;
            sl.delete_pos();
            break;
        case 6:
            cout<<"Update Node Value:"<<endl;
            sl.update();
            cout<<endl;
            break;
        case 7:
            cout<<"Search element in Link List: "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 8:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 9:
            cout<<"Reverse elements of Link List"<<endl;
            sl.reverse();
            cout<<endl;
            break;
        case 10:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;
        case 11:
            cout<<"Reverse elements of Link List pairwise"<<endl;
            temp1 = sl.reverse_recursion_pairwise(start);
            start = temp1;
            cout<<endl;
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
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
void single_llist::insert_begin(){
    cout<<"Enter value to insert in the beginning:"<<endl;
    int n;
    cin>>n;
    node *temp = create_node(n);
    if(start == NULL){
        start = temp;
        start->next = NULL;
    }else{
        temp->next = start;
        start = temp;
    }
}
void single_llist::insert_last(){
    cout<<"Enter value to insert at last :"<<endl;
    int n;
    cin>>n;
    node *temp = create_node(n);
    node *s = start;
    while(s->next != NULL){
        s=s->next;
    }
    s->next = temp;
    temp->next = NULL;
}
void single_llist::insert_pos(){
    cout<<"Enter value to insert in middle:"<<endl;
    int n;
    cin>>n;
    node *temp = create_node(n);
    cout<<"Enter position(acc. to you) to insert :"<<endl;
    int pos;
    cin>>pos;
    node *s = start;
    int counter = 0;
    while( counter != pos-2){
        s=s->next;
        counter++;
    }
    node *p = s->next;
    s->next = temp;
    temp->next = p;
}
void single_llist::display()
{
    node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void single_llist::sort(){
    node *p,*s;
    int value;
    s=start;
    while(s != NULL){
        for(p = s->next; p != NULL;p=p->next){
            if(p->value > s->value){
                value = p->value;
                p->value = s->value;
                s->value = value;
            }
        }
        s=s->next;
    }
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
void single_llist::update(){
    cout<<"Enter position to update value of (acc to you)"<<endl;
    int pos;
    cin>>pos;
    cout<<"Enter new value "<<endl;
    int n;
    cin>>n;
    node *s;
    s= start;
    int counter = 0;
    if(pos == 1){
        s->value = n;
    }else{
        while( counter != pos-1){
            s=s->next;
            counter++;
        }
        s->value = n;
    }

}
void single_llist::search(){
    cout<<"Enter value to search for  "<<endl;
    int n;
    cin>>n;
    node *s;
    s= start;
    int counter = 0,flag = 0;
        while(flag == 0){
            if(s->value == n){
                cout<<"Found at position : "<<counter+1;
                flag = 1;
                break;
            }
            s=s->next;
            counter++;
        }
}
void single_llist::reverse()
{
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (start->next == NULL)
    {
        return;
    }
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
    }
    start = ptr2;
}
node * single_llist::reverse_recursion_pairwise(node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *nextE = head->next;
    head->next = reverse_recursion_pairwise(nextE->next);
    nextE->next = head;
    return nextE;
}
