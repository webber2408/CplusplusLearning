#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack{
    int top;
public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x){
    if(top>= MAX-1){
        cout<<"Stack full"<<endl;
        return false;
    }else{
        a[++top]=x;
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout<<"Stack Empty/Underflow"<<endl;
        return -1;
    }else{
        return a[top--];
    }
}

bool Stack::isEmpty(){
    return (top<0);
}

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    cout<<s.pop();
    cout<<s.pop();
    cout<<s.pop();

    return 0;
}
