#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Queue{
    int *arr;
    int Front;
    int Rear;
    int Capacity;
    int Count;
public:
    Queue(int Size = MAX);
    void Dequeue();
    void Enqueue(int x);
    int Peek();
    int Size();
    bool isEmpty();
    bool isFull();
};
Queue::Queue(int Size){
    arr = new int[Size];
    Capacity=Size;
    Front=0;
    Rear=-1;
    Count=0;
}
void Queue::Dequeue(){
    if(isEmpty()){
        cout<<"Q already empty"<<endl;
        exit(0);
    }
    cout<<arr[Front]<<endl;
    Front = (Front+1)%Capacity;
    Count--;
}

void Queue::Enqueue(int x){
    if(isFull()){
        cout<<"Q already full"<<endl;
        exit(0);
    }
    Rear = (Rear+1)%Capacity;
    arr[Rear]=x;
    Count++;
}

int Queue::Peek(){
   if(isEmpty()){
        cout<<"Q already empty"<<endl;
    }
    return arr[Front];
}

int Queue::Size(){
    return Count;
}

bool Queue::isEmpty(){
    return (Size()==0);
}

bool Queue::isFull(){
    return (Size()==Capacity);
}

int main(){
    Queue q;
    //q.isEmpty();
    //q.Dequeue();
    q.Enqueue(5);
    q.Enqueue(6);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    return 0;
}
