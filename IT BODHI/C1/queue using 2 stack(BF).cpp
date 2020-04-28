#include<bits/stdc++.h>
#include<stack>
using namespace std;
   stack <int> s1;
    stack <int> s2;
void queueIt(int);
void dequeueIt();
int main(){

    int num;
    int choice;
    while(true){

        cout<<"Enter choice : 1.queue 2 . dequeue "<<endl;
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter number :"<<endl;
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
    int temp2;
        if(!s1.empty()){
            while(!s1.empty()){
                temp2 = s1.top();
                s1.pop();
                s2.push(temp2);
            }
            cout<<s2.top()<<endl;
            s2.pop();
            while(!s2.empty()){
                temp2 = s2.top();
                s2.pop();
                s1.push(temp2);
            }
        }else{
            cout<<"No elements"<<endl;
        }
}
