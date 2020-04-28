#include<bits/stdc++.h>
#include<stack>
using namespace std;
void queueIt(int);
void dequeueIt();
stack <int> s1;
stack <int> s2;
int main(){

    int choice;

    while(true){
            cout<<"Enter choice 1. queue 2. dequeue "<<endl;
            cin>>choice;
            switch(choice){
                case 1: cout<<"Enter number "<<endl;
                        int num ;
                        cin>>num;
                        queueIt(num);
                        break;
                case 2: dequeueIt();
                        break;
            }
    }
}
void queueIt(int num){
    s1.push(num);
}
void dequeueIt(){
    int temp;
    if(!s2.empty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }else{
        while(!s1.empty()){
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        cout<<s2.top()<<endl;
        s2.pop();
    }
}
