#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        void display(){
            cout<<"A"<<endl;
        }
        void showInfo(){
            cout<<"I am parent, A!"<<endl;
        }
};

class B: public A{
    public:
        void display(){
            A::showInfo();
            cout<<"B"<<endl;
        }
};

int main(){
    B b;
    b.display();
    cout<<"--------"<<endl;
    b.A::display();
    cout<<"--------"<<endl;
    b.B::display();
    return 0;
}
/*
Output

I am parent, A!
B
--------
A
--------
I am parent, A!
B
*/